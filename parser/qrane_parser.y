%language "c++"
%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%locations
%defines
%verbose

%define parse.assert true
%define parse.trace true
%define parse.error verbose

%define api.token.constructor
%define api.value.type variant
%define api.parser.class {qrane_parser}
%parse-param {std::shared_ptr<Program> mainprogram}

%code requires {
    #ifndef YY_NULLPTR
    #define YY_NULLPTR 0
    #endif

    #ifdef _QRANE_DEBUG_
    #define _D_(x) cout << x << endl
    #else
    #define _D_(x) 
    #endif

    #include "qrane_general.hpp"
    using namespace qrane;
}

%code {
    #define _USE_MATH_DEFINES

    #include <cmath>
    #include <cstddef>
    #include <iostream>
    #include <memory>

    // Declare Flex/Bison variables and functions
    extern yy::qrane_parser::symbol_type yylex();
    extern char *yytext;
    extern yy::location loc;

    //bool qreg_seen = false;
    //unsigned int qreg_size = 0;
    //qop_id qop_count = 0;
}

%token T_OPENQASM               
%token <std::string> T_QREG          
%token <std::string> T_CREG        
%token <std::string> T_GATE_CUSTOM
%token <std::string> T_OPAQUE
%token <std::string> T_BARRIER
%token <std::string> T_MEASURE 
%token <std::string> T_RESET          
%token T_U              
%token T_CX  
%token T_IF                             

%token T_LPAR         "("
%token T_RPAR         ")"
%token T_LCUR         "{"
%token T_RCUR         "}"
%token T_LBRA         "["
%token T_RBRA         "]"
%token T_COMMA        ","
%token T_SEMICOLON    ";"
%token T_ARROW        "->"
%token T_EQLTY        "=="   
%token T_EOF 0        "end of file";

%token <std::string> T_ADD
%token <std::string> T_SUB
%token <std::string> T_MUL
%token <std::string> T_DIV
%token <std::string> T_CARROT
%token <std::string> T_PI
%token <std::string> T_SIN           
%token <std::string> T_COS           
%token <std::string> T_TAN           
%token <std::string> T_EXP           
%token <std::string> T_LN           
%token <std::string> T_SQRT      

%token <std::string>    T_ID             // custom gate name
%token <double>         T_REAL           // real number
%token <unsigned int>   T_UINTEGER       // non-negative integer

%type <std::shared_ptr<qrane::Program>>                    mainprogram;
%type <std::vector<std::shared_ptr<qrane::Element>>>       program;
%type <std::shared_ptr<qrane::Element>>                    statement;
%type <std::shared_ptr<qrane::Decl>>                       decl;
%type <std::shared_ptr<qrane::Decl>>                       gatedecl;
%type <std::shared_ptr<qrane::Reg>>                        reg;
%type <std::shared_ptr<qrane::Qop>>                        qop;
%type <std::shared_ptr<qrane::Qop>>                        uop;
%type <std::vector<std::shared_ptr<qrane::Element>>>       goplist;
%type <std::vector<std::shared_ptr<qrane::Argument>>>      anylist;
%type <std::vector<std::shared_ptr<qrane::Argument>>>      idlist;
%type <std::vector<std::shared_ptr<qrane::Argument>>>      mixedlist;
%type <std::shared_ptr<qrane::Argument>>                   argument;
%type <std::vector<std::shared_ptr<qrane::Parameter>>>     explist;
%type <std::shared_ptr<Parameter>>                         exp;
%type <unary_expr_e>                                       unaryop;

%left T_ADD
%left T_SUB
%left T_MUL
%left T_DIV
%left T_CARROT

%%

mainprogram : T_OPENQASM T_REAL T_SEMICOLON program 
            {
                mainprogram->initialize($4);
            }

program : statement             
        {
	  $$ = std::vector<std::shared_ptr<Element>>();
          $$.push_back($1);
        }      
        | program statement     
        {
            $$ = $1;
            $$.push_back($2);
        }

statement : decl
          {
            $$ = std::static_pointer_cast<Element>($1);
          } 
          | reg
          {
            $$ = std::static_pointer_cast<Element>($1);
          }   
          | qop
          {
            $$ = std::static_pointer_cast<Element>($1);
          }
          | T_IF T_LPAR T_ID T_EQLTY T_UINTEGER T_RPAR qop
          {
              //$$ = $7;
              //$$->set_if_condition($3, $5);
          }

decl : gatedecl goplist T_RCUR
     {
        $$ = $1;
        $$->set_elements($2);
     }                                  
     | gatedecl T_RCUR
     {
        $$ = $1;
     }  

gatedecl : T_GATE_CUSTOM T_ID idlist T_LCUR
         {
            $$ = std::make_shared<Decl>(
                    element_variant_e::DECL, decl_variant_e::GATEDECL,
                    $2, $3);
         }
         | T_GATE_CUSTOM T_ID T_LPAR T_RPAR idlist T_LCUR
         {
            $$ = std::make_shared<Decl>(
                    element_variant_e::DECL, decl_variant_e::GATEDECL,
                    $2, $5);
         }
         | T_GATE_CUSTOM T_ID T_LPAR explist T_RPAR idlist T_LCUR
         {
            $$ = std::make_shared<Decl>(
                    element_variant_e::DECL, decl_variant_e::GATEDECL,
                    $2, $4, $6);
         }

reg : T_QREG T_ID T_LBRA T_UINTEGER T_RBRA T_SEMICOLON
     {
        $$ = std::make_shared<Reg>(
                element_variant_e::REG, reg_variant_e::QREG,
                $1, $2, $4);
     }
     | T_CREG T_ID T_LBRA T_UINTEGER T_RBRA T_SEMICOLON
     {
         $$ = std::make_shared<Reg>(
                element_variant_e::REG, reg_variant_e::CREG,
                $1, $2, $4);
     }

qop : uop
    {
        $$ = $1;
    }
    | T_MEASURE argument T_ARROW argument T_SEMICOLON       // measure q[0]->c[0];
    {
        $$ = std::make_shared<Qop>(
		element_variant_e::QOP, qop_variant_e::MEASURE, 
                $1, std::vector<std::shared_ptr<Argument>>({$2, $4}));
    }
    | T_RESET argument T_SEMICOLON                          // reset q[0];
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::RESET, 
                $1, std::vector<std::shared_ptr<Argument>>({$2}));
    }
    | T_BARRIER anylist T_SEMICOLON
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::BARRIER, 
                $1, $2);
    }
    | T_OPAQUE T_ID idlist T_SEMICOLON
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::OPAQUE, 
                $2, $3);
    }
    | T_OPAQUE T_ID T_LPAR T_RPAR idlist T_SEMICOLON 
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::OPAQUE, 
                $2, $5);
    }
    | T_OPAQUE T_ID T_LPAR explist T_RPAR idlist T_SEMICOLON
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::OPAQUE, 
                $2, $4, $6);
    }

uop : T_ID anylist T_SEMICOLON                              // gate_name q[0],q[2],q[3],q[1];
    {
		
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::GATE, 
                $1, $2);
    }
    | T_ID T_LPAR T_RPAR anylist T_SEMICOLON                // gate_name() q[0],q[2],q[4],q[3];
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::GATE, 
                $1, $4);
    }
    | T_ID T_LPAR explist T_RPAR anylist T_SEMICOLON        // gate_name(2.0,0.0,pi/4) q[0],q[2],q[4];
    {
        $$ = std::make_shared<Qop>(
                element_variant_e::QOP, qop_variant_e::GATE, 
                $1, $3, $5);
    }

goplist : qop
        {
	  $$ = std::vector<std::shared_ptr<Element>>();
            $$.push_back($1); 
        }
        | goplist qop
        {
            $$ = $1;
            $$.push_back($2);
        }

anylist : idlist        { $$ = $1; } 
        | mixedlist     { $$ = $1; }

idlist : T_ID
       {
	 $$ = std::vector<std::shared_ptr<Argument>>();
           $$.push_back(std::make_shared<Argument>($1));
       }
       | idlist T_COMMA T_ID
       {
            $$ = $1;
            $$.push_back(std::make_shared<Argument>($3));
       }

mixedlist : T_ID T_LBRA T_UINTEGER T_RBRA
          {
            $$ = std::vector<std::shared_ptr<Argument>>();
            $$.push_back(std::make_shared<Argument>($1, $3));
          }
          | mixedlist T_COMMA T_ID 
          {
            $$ = $1;
            $$.push_back(std::make_shared<Argument>($3));
          }
          | mixedlist T_COMMA T_ID T_LBRA T_UINTEGER T_RBRA
          {
            $$ = $1;
            $$.push_back(std::make_shared<Argument>($3, $5));
          }
          | idlist T_COMMA T_ID T_LBRA T_UINTEGER T_RBRA
          {
            $$ = $1;
            $$.push_back(std::make_shared<Argument>($3, $5));
          }

argument : T_ID 
         {
            $$ = std::make_shared<Argument>($1);
         }
         | T_ID T_LBRA T_UINTEGER T_RBRA
         {
            $$ = std::make_shared<Argument>($1, $3);
         }

explist : exp
        {
	  $$ = std::vector<std::shared_ptr<Parameter>>();
            $$.push_back($1);
        }
        | explist T_COMMA exp
        {
            $$ = $1;
            $$.push_back($3);
        }

exp : T_REAL                    
    { 
         $$ = std::make_shared<ParameterValue<double>>($1);
    } 
    | T_UINTEGER
    { 
         $$ = std::make_shared<ParameterValue<int>>($1);
    }               
    | T_PI
    { 
         $$ = std::make_shared<ParameterValue<double>>(double(M_PI));
    }                    
    | T_ID
    { 
         $$ = std::make_shared<ParameterValue<std::string>>($1);
    }                      
    | exp T_ADD exp     %prec T_ADD        
    { 
        $$ = std::make_shared<BinaryExpr>(binary_expr_e::ADD, $2, $1, $3);
    }           
    | exp T_SUB exp      %prec T_SUB       
    {
        $$ = std::make_shared<BinaryExpr>(binary_expr_e::SUB, $2, $1, $3);
    }           
    | exp T_MUL exp       %prec T_MUL
    { 
        $$ = std::make_shared<BinaryExpr>(binary_expr_e::MUL, $2, $1, $3);
    }           
    | exp T_DIV exp        %prec T_DIV
    {
        $$ = std::make_shared<BinaryExpr>(binary_expr_e::DIV, $2, $1, $3);
    }           
    | T_SUB exp                 
    { 
        $$ = std::make_shared<UnaryExpr>(unary_expr_e::NEG, $1, $2);
    }         
    | exp T_CARROT exp       %prec T_CARROT
    { 
        $$ = std::make_shared<BinaryExpr>(binary_expr_e::CAR, $2, $1, $3);
    }        
    | T_LPAR exp T_RPAR         
    {
        $$ = std::make_shared<UnaryExpr>(unary_expr_e::PAR, "", $2);
    }                
    | unaryop T_LPAR exp T_RPAR 
    { 
        $$ = std::make_shared<UnaryExpr>($1, "", $3);
    }

unaryop : T_SIN     { $$ = unary_expr_e::SIN;  }
        | T_COS     { $$ = unary_expr_e::COS;  }
        | T_TAN     { $$ = unary_expr_e::TAN;  }
        | T_EXP     { $$ = unary_expr_e::EXP;  }
        | T_LN      { $$ = unary_expr_e::LN;   }
        | T_SQRT    { $$ = unary_expr_e::SQRT; }

%%

void yy::qrane_parser::error (const yy::location & l, const std::string & s) {
	std::cerr << "Qrane parsing error at " << l << " : " << s << std::endl;
}
