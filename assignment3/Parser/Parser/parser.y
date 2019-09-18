%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

int type_int = 0;
int type_void = 0;
int type_float = 0;
int type_char = 0;

void line(int);
extern printError();
extern yylex();
extern yyerror(s);
%}

%token TIDEN TNUMBER TCONST TIF TINT TRETURN TVOID TWHILE TFLOAT TCHAR TSTRING
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE TINC TDEC
%token TPLUS TMINUS TMULTIPLY TDIVIDE TMOD TNOT TASSIGN TLPAREN TRPAREN TCOMMA TSEMICOLON
%token TLBRACKET TRBRACKET TLBRACE TRBRACE
%nonassoc LOWER_THEN_ELSE
%nonassoc TELSE

%%

mini_c	: translation_unit
	;
translation_unit	: external_dcl
		| translation_unit external_dcl
		;
external_dcl	: function_def
		| declaration
		| TIDEN TSEMICOLON
		| TIDEN error
		{
			yyerrok;
			printError(wrong_st);
		}
		;
function_def	: function_header compound_st
		| function_header TSEMICOLON
		| function_header error /*error - 잘못된 함수 정의*/
		{
			look_tmp->type = 0; /*type의 default 값은 0*/
			yyerrok;
			printError(wrong_funcdef);
		}
		;
function_header	: dcl_spec function_name formal_param
				| dcl_spec formal_param /*error - 함수 이름이 정의되지 않았을 경우*/
				{
					yyerrok;
					printError(nofuncname);
				}
		;
dcl_spec		: dcl_specifiers
		;
dcl_specifiers	: dcl_specifier
		| dcl_specifiers dcl_specifier
		;
dcl_specifier	: type_qualifier
		| type_specifier
		;
type_qualifier	: TCONST
		;
type_specifier	: TINT	{type_int=1;} /*실수형에 대한 토큰 type : int*/
		| TVOID	{type_void=1;} /*void형에 대한 토큰 type : void*/
		| TFLOAT {type_float=1;} /*실수형에 대한 토큰 type : float*/
		| TCHAR {type_char=1;} /*문자형에 대한 토큰 type : char*/
		;
function_name	: TIDEN
		{
			if(look_id->type==0 || look_id->type==5)
			{
				if(type_int == 1)
				{
					look_id->type=4; /*정수를 인자로 반환하는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
				else if(type_void == 1)
				{
					look_id->type=6; /*반환하는 인자가 없는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
				else if(type_float == 1)
				{
					look_id->type=7; /*실수를 인자로 반환하는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
				else if(type_char == 1)
				{
					look_id->type=8; /*문자를 인자로 반환하는 함수*/
					type_int = 0;
					type_void = 0;
					type_float = 0;
					type_char = 0;
					look_tmp = look_id;
				}
			 }
		}
		;
formal_param	: TLPAREN opt_formal_param TRPAREN
				| TLPAREN opt_formal_param error /* error - ')'가 없을 경우*/
				{
					yyerrok;
					printError(noparen);
				} 
		;
opt_formal_param 	: formal_param_list
		|
		;
formal_param_list	: param_dcl
		| formal_param_list TCOMMA param_dcl
		| formal_param_list param_dcl /*error - ','가 없을 경우*/
		{
			yyerrok;
			printError(nocomma);
		}
		;
param_dcl	: dcl_spec declarator
		;
compound_st	: TLBRACE compound TRBRACE
		| TLBRACE compound error
		{
			yyerrok;
			printError(nobrace);
		}
		;
compound	: opt_dcl_list opt_stat_list
		;
opt_dcl_list	: declaration_list
		|
		;
declaration_list	: declaration
		| declaration_list declaration
		;
declaration	: dcl_spec init_dcl_list TSEMICOLON
		{
			type_int = 0; /*값 다시 초기화*/
			type_void = 0;
			type_float = 0;
			type_float = 0;
			type_char = 0;
		}
		| dcl_spec init_dcl_list error /*error - ';'가 없을 경우*/
		{
			look_tmp->type = 0;
			yyerrok;
			type_int = 0; /*값 다시 초기화*/
			type_void = 0;
			type_float = 0;
			type_char = 0;
			printError(nosemi);
		}
		;
init_dcl_list	: init_declarator
		| init_dcl_list TCOMMA init_declarator
		;
init_declarator	: declarator
		| declarator TASSIGN TNUMBER
		| declarator TASSIGN TSTRING /*스트링 상수가 assign될 경우*/
		| declarator TASSIGN function_st
		;
declarator	: TIDEN
		{
			if(look_id->type==0)
			{
				if(type_int==1) 
					look_id->type=1; /*정수 상수에 대한 변수*/
				else if(type_float==1) 
					look_id->type=2; /*실수 상수에 대한 변수*/
				else if(type_char==1) 
					look_id->type=9; /*문자에 대한 변수*/
			}
			look_tmp = look_id;
		}
		| TIDEN TLBRACKET opt_number TRBRACKET
		{
			if(look_id->type == 0)
			{
				if(type_int==1)
					look_id->type=3; /*정수 배열에 대한 변수*/
				else if(type_float==1)
					look_id->type=10; /*실수 배열에 대한 변수*/
				else if(type_char==1)
					look_id->type=11; /*문자 배열에 대한 변수*/
				look_tmp = look_id;
			}
		}
		| TIDEN TLBRACKET opt_number error
		{
			yyerrok;
			printError(nobracket);
		}
		;
opt_number	: TNUMBER
		|
		;
opt_stat_list	: statement_list
		|
		;
statement_list	: statement
		| statement_list statement
		| statement_list declaration
		;
statement	: compound_st
		| expression_st
		| if_st
		| while_st
		| return_st
		;
expression_st	: opt_expression TSEMICOLON
		| expression error
		{
			yyerrok;
			printError(nosemi);
		}
		;
opt_expression	: expression
		|
		;
if_st		: TIF TLPAREN expression TRPAREN statement %prec LOWER_THEN_ELSE
		| TIF TLPAREN expression TRPAREN statement TELSE statement
		;
while_st		: TWHILE TLPAREN expression TRPAREN statement
		;
return_st		: TRETURN opt_expression TSEMICOLON
		;
expression	: assignment_exp
		;
function_st	: TPLUS function_expression /*함수 뒤에 나올 연산식을 위한 nonterminal 정의*/
			| TMINUS function_expression
			| TMULTIPLY function_expression
			| TDIVIDE function_expression
			| TMOD function_expression
			;
function_expression : TLPAREN addtive_exp TRPAREN
					| TLPAREN addtive_exp error /*error - ')'가 없을 경우*/
					{
						yyerrok;
						printError(noparen);
					}
assignment_exp	: logical_or_exp
		| unary_exp TASSIGN assignment_exp
		| unary_exp TADDASSIGN assignment_exp
		| unary_exp TSUBASSIGN assignment_exp
		| unary_exp TMULASSIGN assignment_exp
		| unary_exp TDIVASSIGN assignment_exp
		| unary_exp TMODASSIGN assignment_exp
		| opt_number TASSIGN assignment_exp /*잘못된 assign이 될 경우*/
		{
						yyerrok;
						printError(assignerr);
		}
		;
logical_or_exp	: logical_and_exp
		| logical_or_exp TOR logical_and_exp
		;
logical_and_exp	: equality_exp
		| logical_and_exp TAND equality_exp
		;
equality_exp	: relational_exp
		| equality_exp TEQUAL relational_exp
		| equality_exp TNOTEQU relational_exp
		;
relational_exp	: addtive_exp
		| relational_exp TGREAT addtive_exp
		| relational_exp TLESS addtive_exp
		| relational_exp TGREATE addtive_exp
		| relational_exp TLESSE addtive_exp
		;
addtive_exp	: multiplicative_exp
		| addtive_exp TPLUS multiplicative_exp
		| addtive_exp TMINUS multiplicative_exp
		;
multiplicative_exp	: unary_exp
		| multiplicative_exp TMULTIPLY unary_exp
		| multiplicative_exp TDIVIDE unary_exp
		| multiplicative_exp TMOD unary_exp
		;
unary_exp	: postfix_exp
		| TMINUS unary_exp
		| TNOT unary_exp
		| TINC unary_exp
		| TDEC unary_exp
		;
postfix_exp	: primary_exp
		| postfix_exp TLBRACKET expression TRBRACKET
		| postfix_exp TLPAREN opt_actual_param TRPAREN
		| postfix_exp TINC
		| postfix_exp TDEC
		| postfix_exp TLBRACKET expression error
		{
			yyerrok;
			printError(nobracket);
		}

		;
opt_actual_param	: actual_param
		|
		;
actual_param	: actual_param_list	
		;
actual_param_list	: assignment_exp
		| actual_param_list TCOMMA assignment_exp
		;
primary_exp	: TIDEN
		{
			if(look_id->type==0)
				look_id->type = 5;
		}
		| TNUMBER
		| TLPAREN expression TRPAREN
		;
%%

void line(int n)
{
	printf("\t %d \t", n);
}