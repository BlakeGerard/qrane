%{ 
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#include "qrane_general.hh"

// Flex incompatibility protection
# undef yywrap
# define yywrap() 1

// yylex() declaration
#undef YY_DECL
#define YY_DECL yy::qrane_parser::symbol_type yylex()
YY_DECL;

// Location declaration
yy::location loc;

// Code run each time a pattern is matched.
#define YY_USER_ACTION  loc.columns(yyleng);

// Counter to track number of include buffers
int num_incl_buffs = 0;

//std::string qrane_home = std::string(std::getenv("QRANE_HOME"));
//std::string qelib = qrane_home + "/qelib1.inc";

%}

%option yylineno
%option noyywrap
%option nounput

ID [a-z][A-Za-z0-9_]*
REAL ([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?
NNINTEGER [1-9]+[0-9]*|0

%x incl

%%

\/\/.*$

[ \t]+		{ 
				loc.step(); 
			}
		
[\n]+		{ 
				loc.lines(yyleng); loc.step(); 
			}

"OPENQASM"  { 
				return yy::qrane_parser::make_T_OPENQASM(loc); 
			}

^include.*  {
               // Skip include directives.
            }

"qreg"  	{ 
				return yy::qrane_parser::make_T_QREG(loc); 
			}

"creg"  	{ 
				return yy::qrane_parser::make_T_CREG(loc); 
			}

"gate"  	{
				return yy::qrane_parser::make_T_GATE_CUSTOM(loc); 
			}

"barrier"	{ 
				return yy::qrane_parser::make_T_BARRIER(loc); 
			}

"opaque"	{ 
				return yy::qrane_parser::make_T_OPAQUE(loc); 
			}

"if"		{ 
				return yy::qrane_parser::make_T_IF(loc); 
			}

"measure"	{ 
				return yy::qrane_parser::make_T_MEASURE(loc); 
			}

"reset"		{ 
				return yy::qrane_parser::make_T_RESET(loc); 
			}

"U"			{ 
				return yy::qrane_parser::make_T_U(loc); 
			}

"CX"		{  
				return yy::qrane_parser::make_T_CX(loc); 
			}

"("			{  
				return yy::qrane_parser::make_T_LPAR(loc); 
			}

")"			{  
				return yy::qrane_parser::make_T_RPAR(loc); 
			}

"{"			{  
				return yy::qrane_parser::make_T_LCUR(loc); 
			}

"}"			{  
				return yy::qrane_parser::make_T_RCUR(loc); 
			}

"["			{  
				return yy::qrane_parser::make_T_LBRA(loc); 
			}

"]"			{ 
				return yy::qrane_parser::make_T_RBRA(loc); 
			}

","			{  
				return yy::qrane_parser::make_T_COMMA(loc); 
			}

";"			{  
				return yy::qrane_parser::make_T_SEMICOLON(loc); 
			}

"->"		{  
				return yy::qrane_parser::make_T_ARROW(loc); 
			}

"+"			{  
				return yy::qrane_parser::make_T_ADD(loc); 
			}

"-"			{  
				return yy::qrane_parser::make_T_SUB(loc); 
			}

"*"			{ 
				return yy::qrane_parser::make_T_MUL(loc); 
			}

"/"			{  
				return yy::qrane_parser::make_T_DIV(loc); 
			}

"^"			{  
				return yy::qrane_parser::make_T_CARROT(loc); 
			}

"=="		{  
				return yy::qrane_parser::make_T_EQLTY(loc); 
			}

"pi"		{ 
				return yy::qrane_parser::make_T_PI(loc); 
			}

"sin"		{  
				return yy::qrane_parser::make_T_SIN(loc); 
			}

"cos"		{  
				return yy::qrane_parser::make_T_COS(loc); 
			}

"tan"		{  
				return yy::qrane_parser::make_T_TAN(loc); 
			}

"exp"		{  
				return yy::qrane_parser::make_T_EXP(loc); 
			}

"ln"		{  
				return yy::qrane_parser::make_T_LN(loc); 
			}

"sqrt"		{  
				return yy::qrane_parser::make_T_SQRT(loc); 
			}

{ID}		{ 
    			return yy::qrane_parser::make_T_ID(std::string(yytext), loc);
			}

{REAL}		{
			    return yy::qrane_parser::make_T_REAL(atol(yytext), loc);
			}

{NNINTEGER}	{
				return yy::qrane_parser::make_T_NNINTEGER(atoi(yytext), loc);
		    }

<incl>[ \t]*
<incl>\".*\";
            {
                /*
			    std::string file = std::string(yytext);
			    file.erase(std::remove(file.begin(), file.end(), '\"'), file.end());
			    file.erase(std::remove(file.begin(), file.end(), ';'), file.end());

			    yyin = fopen(qelib.c_str(), "r");
			    if (!yyin) { printf("Could not open include file.\n"); exit(1); }
			    ++num_incl_buffs;
			    yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));					
			    BEGIN(INITIAL);
                */
		    }

<<EOF>>		{ 
				if (num_incl_buffs > 0) {
					yypop_buffer_state();
					--num_incl_buffs; 
				} else {
  					return yy::qrane_parser::make_T_EOF(loc);
				}
			}

.			{ 
				std::cout << "Unexpected character: " << yytext << std::endl;
				exit(1);
			}

%%