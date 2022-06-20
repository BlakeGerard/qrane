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
%parse-param {std::shared_ptr<qrane_program> mainprogram}

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
	using namespace qrane
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

    bool qreg_seen = false;
    unsigned int qreg_size = 0;
    qop_id qop_count = 0;
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
%type <unaryop_type>                                       unaryop;

%left T_ADD
%left T_SUB
%left T_MUL
%left T_DIV
%left T_CARROT

%%

mainprogram : T_OPENQASM T_REAL T_SEMICOLON program 
            {
                mainprogram->initialize($4, qreg_size);
            }

program : statement             
        {
            $$ = qrane_statementlist();
            $$.append($1);
        }      
        | program statement     
        {
            $$ = $1;
            $$.append($2);
        }

statement : decl
          {
            $$ = std::static_pointer_cast<qrane_statement>($1);
          } 
          | reg
          {
            $$ = std::static_pointer_cast<qrane_statement>($1);
          }   
          | qop
          {
            $$ = std::static_pointer_cast<qrane_statement>($1);
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
            $$ = std::make_shared<qrane_decl>(
                    statement_type::DECL, decl_type::GATEDECL,
                    $2, $3);
         }
         | T_GATE_CUSTOM T_ID T_LPAR T_RPAR idlist T_LCUR
         {
            $$ = std::make_shared<qrane_decl>(
                    statement_type::DECL, decl_type::GATEDECL,
                    $2, $5);
         }
         | T_GATE_CUSTOM T_ID T_LPAR explist T_RPAR idlist T_LCUR
         {
            $$ = std::make_shared<qrane_decl>(
                    statement_type::DECL, decl_type::GATEDECL,
                    $2, $4, $6);
         }

reg : T_QREG T_ID T_LBRA T_UINTEGER T_RBRA T_SEMICOLON
     {
        qreg_seen = true;
		qreg_size = $4;
         $$ = std::make_shared<qrane_reg>(
                statement_type::REG, reg_type::QREG,
                $1, $2, $4);
     }
     | T_CREG T_ID T_LBRA T_UINTEGER T_RBRA T_SEMICOLON
     {
         $$ = std::make_shared<qrane_reg>(
                statement_type::REG, reg_type::CREG,
                $1, $2, $4);
     }

qop : uop
    {
        $$ = $1;
    }
    | T_MEASURE argument T_ARROW argument T_SEMICOLON       // measure q[0]->c[0];
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::MEASURE, 
                qop_count, $1, qrane_argumentlist({$2, $4}));
        if (qreg_seen) { qop_count += 1; }
    }
    | T_RESET argument T_SEMICOLON                          // reset q[0];
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::RESET, 
                qop_count, $1, qrane_argumentlist({$2}));
        if (qreg_seen) { qop_count += 1; }
    }
    | T_BARRIER anylist T_SEMICOLON
    {
        if (qreg_seen) { mainprogram->increment_num_qops(); }
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::BARRIER, 
                qop_count, $1, $2);
        if (qreg_seen) { qop_count += 1; }
    }
    | T_OPAQUE T_ID idlist T_SEMICOLON
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::OPAQUE, 
                qop_count, $2, $3);
        if (qreg_seen) { qop_count += 1; }
    }
    | T_OPAQUE T_ID T_LPAR T_RPAR idlist T_SEMICOLON 
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::OPAQUE, 
                qop_count, $2, $5);
        if (qreg_seen) { qop_count += 1; }
    }
    | T_OPAQUE T_ID T_LPAR explist T_RPAR idlist T_SEMICOLON
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::OPAQUE, 
                qop_count, $2, $4, $6);
        if (qreg_seen) { qop_count += 1; }
    }

uop : T_ID anylist T_SEMICOLON                              // gate_name q[0],q[2],q[3],q[1];
    {
		
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::GATE, 
                qop_count, $1, $2);
        if (qreg_seen) { qop_count += 1; }
    }
    | T_ID T_LPAR T_RPAR anylist T_SEMICOLON                // gate_name() q[0],q[2],q[4],q[3];
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::GATE, 
                qop_count, $1, $4);
        if (qreg_seen) { qop_count += 1; }
    }
    | T_ID T_LPAR explist T_RPAR anylist T_SEMICOLON        // gate_name(2.0,0.0,pi/4) q[0],q[2],q[4];
    {
        $$ = std::make_shared<qrane_qop>(
                statement_type::QOP, qop_type::GATE, 
                qop_count, $1, $3, $5);
        if (qreg_seen) { qop_count += 1; }
    }

goplist : qop
        {
            $$ = qrane_statementlist();
            $$.append($1); 
        }
        | goplist qop
        {
            $$ = $1;
            $$.append($2);
        }

anylist : idlist        { $$ = $1; } 
        | mixedlist     { $$ = $1; }

idlist : T_ID
       {
           $$ = qrane_argumentlist();
           $$.append(std::make_shared<qrane_argument>($1));
       }
       | idlist T_COMMA T_ID
       {
            $$ = $1;
            $$.append(std::make_shared<qrane_argument>($3));
       }

mixedlist : T_ID T_LBRA T_UINTEGER T_RBRA
          {
            $$ = qrane_argumentlist();
            $$.append(std::make_shared<qrane_argument>($1, $3));
          }
          | mixedlist T_COMMA T_ID 
          {
            $$ = $1;
            $$.append(std::make_shared<qrane_argument>($3));
          }
          | mixedlist T_COMMA T_ID T_LBRA T_UINTEGER T_RBRA
          {
            $$ = $1;
            $$.append(std::make_shared<qrane_argument>($3, $5));
          }
          | idlist T_COMMA T_ID T_LBRA T_UINTEGER T_RBRA
          {
            $$ = $1;
            $$.append(std::make_shared<qrane_argument>($3, $5));
          }

argument : T_ID 
         {
            $$ = std::make_shared<qrane_argument>($1);
         }
         | T_ID T_LBRA T_UINTEGER T_RBRA
         {
            $$ = std::make_shared<qrane_argument>($1, $3);
         }

explist : exp
        {
            $$ = qrane_parameterlist();
            $$.append($1);
        }
        | explist T_COMMA exp
        {
            $$ = $1;
            $$.append($3);
        }

exp : T_REAL                    
    { 
         $$ = std::make_shared<qrane_value<double>>($1);
    } 
    | T_UINTEGER
    { 
         $$ = std::make_shared<qrane_value<int>>($1);
    }               
    | T_PI
    { 
         $$ = std::make_shared<qrane_value<double>>(double(M_PI));
    }                    
    | T_ID
    { 
         $$ = std::make_shared<qrane_value<std::string>>($1);
    }                      
    | exp T_ADD exp     %prec T_ADD        
    { 
        $$ = std::make_shared<qrane_binaryop>(binaryop_type::ADD, $2, $1, $3);
    }           
    | exp T_SUB exp      %prec T_SUB       
    {
        $$ = std::make_shared<qrane_binaryop>(binaryop_type::SUB, $2, $1, $3);
    }           
    | exp T_MUL exp       %prec T_MUL
    { 
        $$ = std::make_shared<qrane_binaryop>(binaryop_type::MUL, $2, $1, $3);
    }           
    | exp T_DIV exp        %prec T_DIV
    {
        $$ = std::make_shared<qrane_binaryop>(binaryop_type::DIV, $2, $1, $3);
    }           
    | T_SUB exp                 
    { 
        $$ = std::make_shared<qrane_unaryop>(unaryop_type::NEG, $1, $2);
    }         
    | exp T_CARROT exp       %prec T_CARROT
    { 
        $$ = std::make_shared<qrane_binaryop>(binaryop_type::CAR, $2, $1, $3);
    }        
    | T_LPAR exp T_RPAR         
    {
        $$ = std::make_shared<qrane_unaryop>(unaryop_type::PAR, "", $2);
    }                
    | unaryop T_LPAR exp T_RPAR 
    { 
        $$ = std::make_shared<qrane_unaryop>($1, "", $3);
    }

unaryop : T_SIN     { $$ = unaryop_type::SIN;  }
        | T_COS     { $$ = unaryop_type::COS;  }
        | T_TAN     { $$ = unaryop_type::TAN;  }
        | T_EXP     { $$ = unaryop_type::EXP;  }
        | T_LN      { $$ = unaryop_type::LN;   }
        | T_SQRT    { $$ = unaryop_type::SQRT; }

%%

void yy::qrane_parser::error (const yy::location & l, const std::string & s) {
	std::cerr << "Qrane parsing error at " << l << " : " << s << std::endl;
}