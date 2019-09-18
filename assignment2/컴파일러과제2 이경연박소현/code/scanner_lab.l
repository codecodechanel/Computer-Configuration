%{
/*
 * scanner_lab.l - lexical analyzer 
 *렉스를 통해 토큰을 쪼개고  종류를 정한다.
 * Programmer - 이경연, 박소현
 *
 * date - 19.04.26
 *
 * 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

%}
%%

"const"					return(TCONST);
"else"					return(TELSE);
"if"					return(TIF);
"int"					return(TINT);
"return"				return(TRETURN);
"void"					return(TVOID);
"while"					return(TWHILE);

"+"					return(TPLUS);
"-"					return(TMINUS);
"*"					return(TMUL);
"/"					return(TDIV);
"%"					return(TPERCENT);

"="                     return(TASSIGN);
"+="					return(TADDASSIGN);
"-="					return(TSUBASSIGN);
"*="					return(TMULASSIGN);
"/="					return(TDIVASSIGN);
"%="					return(TMODASSIGN);

"!"                     return(TNOT);
"&&"					return(TAND);
"||"					return(TOR);


"=="					return(TEQUAL);
"!="					return(TNOTEQU);
"<"                     return(TLESS);
">"                     return(TGREAT);
"<="					return(TEQLESS);
">="					return(TEQGREAT);

"++"					return(TINC);
"--"					return(TDEC);


"("					return(TSMALLBRACE_L);
")"					return(TSMALLBRACE_R);
"["					return(TBIGBRACE_L);
"]"					return(TBIGBRACE_R);
"{"					return(TMIDBRACE_L);
"}"					return(TMIDBRACE_R);
[,]					return(TCOLON);
[;]					return(TSEMICOLON);

[\n]				return(TNEWLINE);
[ \t]						;


"/*"([^*]|\*+[^*/])*\**"*/"		;
"//".*					;


0[0-7]+            return(TOCTA);
0(x|X)[0-9A-Fa-f]+      return(THEXA);
0|[1-9][0-9]*         return(TNUMBER);
[+-]?([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)? return(TREAL);

[A-Za-z_][A-Za-z0-9_][A-Za-z0-9_][A-Za-z0-9_][A-Za-z0-9_][A-Za-z0-9_][A-Za-z0-9_][A-Za-z0-9_][A-Za-z0-9_]+		return(TLONGERR);
[A-Za-z_][A-Za-z0-9_]*		return(TIDENT);
\"(([^\"]|\\\")*[^\\])?\"             return(TSTRING);
\'[^'][']             return(TCHAR);

[1-9][0-9]*[A-Za-z0-9_]+              return(TERROR_DIGIT_START);
[A-Za-z_]+[^A-Za-z0-9_ \n\t(){}[]]+[A-Za-z0-9_]*?	return(TERROR_ILL_CHAR_1);
[^A-Za-z0-9_ \n\t(){}[]]+[A-Za-z0-9_]*?	return(TERROR_ILL_CHAR_2);
.                return(TERROR);
%%

int yywrap()
{
	return 1;
}
