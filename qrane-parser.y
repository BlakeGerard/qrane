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
%parse-param {qrane_mainprogram* mainprogram}

%code requires {
    #ifndef YY_NULLPTR
    #define YY_NULLPTR 0
    #endif

    #ifdef _QRANE_DEBUG_
    #define _D_(x) cout << x << endl
    #else
    #define _D_(x) 
    #endif

    #include "qrane_general.hh"
}

%code {
    #define _USE_MATH_DEFINES

    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
    #include <cmath>
    #include <string.h>
    #include <cstddef>
    #include <string>
    #include <vector>
    #include <map>
    #include <string>
    #include <iostream>

    // Declare Flex/Bison variables and functions
    extern yy::qrane_parser::symbol_type yylex();
    extern char *yytext;
    extern yy::location loc;

    // Keep track of each qop's number in the sequence
    bool qreg_decl_seen = false;
    int dim1_qop_num = -1;
    unsigned int domain_nums = -1;
}

%token T_OPENQASM               
%token T_QREG          
%token T_CREG        
%token T_GATE_CUSTOM
%token T_OPAQUE
%token T_BARRIER
%token T_MEASURE 
%token T_RESET          
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
%token T_ADD          "+"
%token T_SUB          "-"
%token T_MUL          "*"
%token T_DIV          "/"
%token T_CARROT       "^"
%token T_EQLTY        "=="
%token T_EOF 0        "end of file";

%token T_PI                       
%token T_SIN           
%token T_COS           
%token T_TAN           
%token T_EXP           
%token T_LN           
%token T_SQRT          

//%token <semantic_value> name
%token <std::string>    T_ID             // custom gate name
%token <double>         T_REAL           // real number
%token <int>            T_NNINTEGER      // non-negative integer

%type <qrane_mainprogram*>      mainprogram;
%type <qrane_stmtlist*>         program;
%type <qrane_statement*>        statement;
%type <qrane_decl*>             decl;
%type <qrane_decl*>             gatedecl;
%type <qrane_stmtlist*>         goplist;
%type <qrane_qop*>              qop;
%type <qrane_qop*>              uop;
%type <qrane_arglist*>          anylist;
%type <qrane_idlist*>           idlist;
%type <qrane_arglist*>          mixedlist;
%type <qrane_argument*>         argument;
%type <qrane_explist*>          explist;
%type <qrane_exp*>              exp;
%type <qrane_exp::unaryop_type> unaryop;

%left T_ADD
%left T_SUB
%left T_MUL
%left T_DIV
%left T_CARROT

%%

mainprogram : T_OPENQASM T_REAL T_SEMICOLON program 
            {
                mainprogram->add_stmtlist($4);
            }

program : statement             
        {
            $$ = new qrane_stmtlist();
            $$->add_statement($1);
        }      
        | program statement     
        {
            $$ = $1;
            $$->add_statement($2);
        }

statement : decl 
          {
            $$ = $1;
          }                                                        
          | gatedecl goplist T_RCUR
          {
            $1->set_goplist($2);
            $$ = $1;
          }                                  
          | gatedecl T_RCUR
          {
            $$ = $1;
          }                                     
          | T_OPAQUE T_ID idlist T_SEMICOLON
          {
            qrane_decl *opaque = new qrane_opaque();
            opaque->set_statement_type(qrane_statement::statement_type::DECL);
            opaque->set_decl_type(qrane_decl::decl_type::OPAQUE);
            opaque->set_id($2);
            opaque->set_paramlist(new qrane_idlist());
            opaque->set_arglist($3);
            $$ = opaque;
          }
          | T_OPAQUE T_ID T_LPAR T_RPAR idlist T_SEMICOLON 
          {
            qrane_decl *opaque = new qrane_opaque();
            opaque->set_statement_type(qrane_statement::statement_type::DECL);
            opaque->set_decl_type(qrane_decl::decl_type::OPAQUE);
            opaque->set_id($2);
            opaque->set_paramlist(new qrane_idlist());
            opaque->set_arglist($5);
            $$ = opaque;
          }
          | T_OPAQUE T_ID T_LPAR idlist T_RPAR idlist T_SEMICOLON
          {
            qrane_decl *opaque = new qrane_opaque();
            opaque->set_statement_type(qrane_statement::statement_type::DECL);
            opaque->set_decl_type(qrane_decl::decl_type::OPAQUE);
            opaque->set_id($2);
            opaque->set_paramlist($4);
            opaque->set_arglist($6);
            $$ = opaque;
          }
          | qop
          {
              $$ = $1;
              //mainprogram->parse_iteration_domains_online($$, domain_nums);
          }
          | T_IF T_LPAR T_ID T_EQLTY T_NNINTEGER T_RPAR qop
          {
              $$ = $7;
              $$->set_if_condition($3, $5);
          }
          | T_BARRIER anylist T_SEMICOLON
          {
            qrane_decl *barrier = new qrane_barrier();
            barrier->set_statement_type(qrane_statement::statement_type::DECL);
            barrier->set_decl_type(qrane_decl::decl_type::BARRIER);
            barrier->set_arglist($2);
            $$ = barrier;
          }

decl : T_QREG T_ID T_LBRA T_NNINTEGER T_RBRA T_SEMICOLON
     {
         mainprogram->qreg_seen = true;
		 mainprogram->qreg_size = $4;
         qrane_decl *qreg = new qrane_qreg();
         qreg->set_statement_type(qrane_statement::statement_type::QREG);
         qreg->set_decl_type(qrane_decl::decl_type::QREG);
         qreg->set_id($2);
         qreg->set_size($4);
         $$ = qreg;
     }
     | T_CREG T_ID T_LBRA T_NNINTEGER T_RBRA T_SEMICOLON
     {
         qrane_decl *creg = new qrane_creg();
         creg->set_statement_type(qrane_statement::statement_type::DECL);
         creg->set_decl_type(qrane_decl::decl_type::CREG);
         creg->set_id($2);
         creg->set_size($4);
         $$ = creg;
     }

gatedecl : T_GATE_CUSTOM T_ID idlist T_LCUR
         {
            qrane_gatedecl *gate = new qrane_gatedecl();
            gate->set_statement_type(qrane_statement::statement_type::DECL);
            gate->set_decl_type(qrane_decl::decl_type::GATE);
            gate->set_id($2);
            gate->set_arglist($3);
            gate->set_paramlist(new qrane_idlist());
            gate->set_goplist(new qrane_stmtlist());
            $$ = gate;
         }
         | T_GATE_CUSTOM T_ID T_LPAR T_RPAR idlist T_LCUR
         {
            qrane_gatedecl *gate = new qrane_gatedecl();
            gate->set_statement_type(qrane_statement::statement_type::DECL);
            gate->set_decl_type(qrane_decl::decl_type::GATE);
            gate->set_id($2);
            gate->set_arglist($5);
            gate->set_paramlist(new qrane_idlist());
            gate->set_goplist(new qrane_stmtlist());
            $$ = gate;
         }
         | T_GATE_CUSTOM T_ID T_LPAR idlist T_RPAR idlist T_LCUR
         {
            qrane_gatedecl *gate = new qrane_gatedecl();
            gate->set_statement_type(qrane_statement::statement_type::DECL);
            gate->set_decl_type(qrane_decl::decl_type::GATE);
            gate->set_id($2);
            gate->set_paramlist($4);
            gate->set_arglist($6);
            gate->set_goplist(new qrane_stmtlist());
            $$ = gate;
         }

goplist : uop
        {
            $$ = new qrane_stmtlist();
            $$->add_statement($1); 
        }
        | T_BARRIER idlist T_SEMICOLON
        {
            $$ = new qrane_stmtlist();
            qrane_decl* barrier = new qrane_barrier();
            barrier->set_statement_type(qrane_statement::statement_type::DECL);
            barrier->set_decl_type(qrane_decl::decl_type::BARRIER);
            barrier->set_idlist($2);
            $$->add_statement(barrier);
        }
        | goplist uop
        {
            $$ = $1;
            $$->add_statement($2);
        }
        | goplist T_BARRIER idlist T_SEMICOLON
        {
            $$ = $1;
            qrane_decl* barrier = new qrane_barrier();
            barrier->set_statement_type(qrane_statement::statement_type::DECL);
            barrier->set_decl_type(qrane_decl::decl_type::BARRIER);
            barrier->set_idlist($3);
            $$->add_statement(barrier);
        }

qop : uop
    {
        $$ = $1;
    }
    | T_MEASURE argument T_ARROW argument T_SEMICOLON       // measureq[0]->c[0];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *measure = new qrane_measure();
        measure->set_statement_type(qrane_statement::statement_type::QOP);
        measure->set_qop_type(qrane_qop::qop_type::MEASURE);
        //measure->set_dim1_qop_num(dim1_qop_num); 
		measure->set_dim1_qop_num(mainprogram->get_num_qops());      
        
        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument($2);
        arglist->add_argument($4);
        measure->set_arglist(arglist);
        $$ = measure;
    }
    | T_RESET argument T_SEMICOLON                          // resetq[0];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *reset = new qrane_reset();
        reset->set_statement_type(qrane_statement::statement_type::QOP);           
        reset->set_qop_type(qrane_qop::qop_type::RESET);
        //reset->set_dim1_qop_num(dim1_qop_num);
		reset->set_dim1_qop_num(mainprogram->get_num_qops());

        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument($2);
        reset->set_arglist(arglist);
        $$ = reset;
    }

uop : T_U T_LPAR explist T_RPAR argument T_SEMICOLON        // U(2.0,0.0,1.0)q[1];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if (mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *u = new qrane_u();
        u->set_statement_type(qrane_statement::statement_type::QOP);                       
        u->set_qop_type(qrane_qop::qop_type::U);
        //u->set_dim1_qop_num(dim1_qop_num);
		u->set_dim1_qop_num(mainprogram->get_num_qops());
        u->set_explist($3);

        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument($5);
        u->set_arglist(arglist);
        $$ = u;
    }        
    | T_CX argument T_COMMA argument T_SEMICOLON            // CXq[1],q[2];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *cx = new qrane_cx();
        cx->set_statement_type(qrane_statement::statement_type::QOP);
        cx->set_qop_type(qrane_qop::qop_type::CX);
        //cx->set_dim1_qop_num(dim1_qop_num);
		cx->set_dim1_qop_num(mainprogram->get_num_qops());

        qrane_arglist *arglist = new qrane_mixedlist();
        arglist->add_argument($2);
        arglist->add_argument($4);
        cx->set_arglist(arglist);
        $$ = cx;
    }
    | T_ID anylist T_SEMICOLON                              // gate_name q[0],q[2],q[3],q[1];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *custom = new qrane_custom();
        custom->set_statement_type(qrane_statement::statement_type::QOP);
        custom->set_qop_type(qrane_qop::qop_type::CUSTOM);
        //custom->set_dim1_qop_num(dim1_qop_num);
		custom->set_dim1_qop_num(mainprogram->get_num_qops());
        custom->set_id($1);
        custom->set_explist(new qrane_explist());
        custom->set_arglist($2);
        $$ = custom;
    }
    | T_ID T_LPAR T_RPAR anylist T_SEMICOLON                // gate_name() q[0],q[2],q[4],q[3];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *custom = new qrane_custom();
        custom->set_statement_type(qrane_statement::statement_type::QOP);
        custom->set_qop_type(qrane_qop::qop_type::CUSTOM);
        //custom->set_dim1_qop_num(dim1_qop_num);
		custom->set_dim1_qop_num(mainprogram->get_num_qops());
        custom->set_id($1);
        custom->set_explist(new qrane_explist());
        custom->set_arglist($4);
        $$ = custom;
    }
    | T_ID T_LPAR explist T_RPAR anylist T_SEMICOLON        // gate_name(2.0,0.0,pi/4) q[0],q[2],q[4];
    {
        //if (qreg_decl_seen) {++dim1_qop_num;}
		if ( mainprogram->qreg_seen) { mainprogram->increment_num_qops(); }
        qrane_qop *custom = new qrane_custom();
        custom->set_statement_type(qrane_statement::statement_type::QOP);
        custom->set_qop_type(qrane_qop::qop_type::CUSTOM);
        //custom->set_dim1_qop_num(dim1_qop_num);
		custom->set_dim1_qop_num(mainprogram->get_num_qops());
        custom->set_id($1);
        custom->set_explist($3);
        custom->set_arglist($5);
        $$ = custom;
    }

anylist : idlist        { $$ = $1; } 
        | mixedlist     { $$ = $1; }

idlist : T_ID
       {
            qrane_idlist* idlist = new qrane_idlist();
            idlist->set_type(qrane_arglist::arglist_type::IDLIST);
            idlist->add_id($1);
            $$ = idlist;
       }
       | idlist T_COMMA T_ID
       {
            $$ = $1;
            $$->add_id($3);
       }

mixedlist : T_ID T_LBRA T_NNINTEGER T_RBRA
          {
            qrane_arglist* mixedlist = new qrane_mixedlist();
            qrane_argument* arg = new qrane_argument($1, $3);
            mixedlist->set_type(qrane_arglist::arglist_type::MIXED);
            mixedlist->add_argument(arg);
            $$ = mixedlist;
          }
          | mixedlist T_COMMA T_ID 
          {
            qrane_argument* arg = new qrane_argument($3);

            $$ = $1;
            $$->add_argument(arg);
          }
          | mixedlist T_COMMA T_ID T_LBRA T_NNINTEGER T_RBRA
          {
            qrane_argument* arg = new qrane_argument($3, $5);

            $$ = $1;
            $$->add_argument(arg);
          }
          | idlist T_COMMA T_ID T_LBRA T_NNINTEGER T_RBRA
          {
            $$ = $1;
            $$->add_id($3);
          }

argument : T_ID 
         {
            qrane_argument* arg = new qrane_argument($1);
            $$ = arg;
         }
         | T_ID T_LBRA T_NNINTEGER T_RBRA
         {
            qrane_argument* arg = new qrane_argument($1, $3);
            $$ = arg;
         }

explist : exp
        {
            $$ = new qrane_explist();
            $$->add_exp($1);
        }
        | explist T_COMMA exp
        {
            $$ = $1;
            $$->add_exp($3);
        }

exp : T_REAL                    
    { 
         qrane_exp* real = new qrane_value<double>($1);
         $$ = real;
    } 
    | T_NNINTEGER
    { 
         qrane_exp* nninteger = new qrane_value<int>($1);
         $$ = nninteger;
    }               
    | T_PI
    { 
         qrane_exp* pi = new qrane_value<double>(double(M_PI));
         $$ = pi;
    }                    
    | T_ID
    { 
         qrane_exp* id = new qrane_value<std::string>($1);
         $$ = id;
    }                      
    | exp T_ADD exp     %prec T_ADD        
    { 
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::ADD);
        binaryop->set_lhs($1);
        binaryop->set_rhs($3);
        $$ = binaryop;
    }           
    | exp T_SUB exp      %prec T_SUB       
    {
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::SUB);
        binaryop->set_lhs($1);
        binaryop->set_rhs($3);
        $$ = binaryop;
    }           
    | exp T_MUL exp       %prec T_MUL
    { 
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::MUL);
        binaryop->set_lhs($1);
        binaryop->set_rhs($3);
        $$ = binaryop;
    }           
    | exp T_DIV exp        %prec T_DIV
    {
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::DIV);
        binaryop->set_lhs($1);
        binaryop->set_rhs($3);
        $$ = binaryop;
    }           
    | T_SUB exp                 
    { 
        qrane_exp* unaryop = new qrane_unaryop();
        unaryop->set_unaryop_type(qrane_exp::unaryop_type::NEG);
        unaryop->set_arg($2);
        $$ = unaryop;
    }         
    | exp T_CARROT exp       %prec T_CARROT
    { 
        qrane_exp* binaryop = new qrane_binaryop();
        binaryop->set_binaryop_type(qrane_exp::binaryop_type::CAR);
        binaryop->set_lhs($1);
        binaryop->set_rhs($3);
        $$ = binaryop;
    }        
    | T_LPAR exp T_RPAR         
    {
        qrane_exp* unaryop = new qrane_unaryop();
        unaryop->set_unaryop_type(qrane_exp::unaryop_type::PAR);
        unaryop->set_arg($2);
        $$ = unaryop;
    }                
    | unaryop T_LPAR exp T_RPAR 
    { 
        qrane_exp* unaryop = new qrane_unaryop();
        unaryop->set_unaryop_type($1);
        unaryop->set_arg($3);
        $$ = unaryop;
    }

unaryop : T_SIN     { $$ = qrane_exp::unaryop_type::SIN;  }
        | T_COS     { $$ = qrane_exp::unaryop_type::COS;  }
        | T_TAN     { $$ = qrane_exp::unaryop_type::TAN;  }
        | T_EXP     { $$ = qrane_exp::unaryop_type::EXP;  }
        | T_LN      { $$ = qrane_exp::unaryop_type::LN;   }
        | T_SQRT    { $$ = qrane_exp::unaryop_type::SQRT; }

%%

void yy::qrane_parser::error (const yy::location & l, const std::string & s) {
	std::cerr << "Qrane parsing error at " << l << " : " << s << std::endl;
}