%{
/*lex source for Mini C*/
/*실행을 위해 추가한 부분*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
extern ComputeHS(int nid, int nfree);
extern LookupHS(int nid, int nfree);
extern ADDHT(int hscode);
extern PrintHStable();
extern yyerror(char *s);

int i;
%}

%s CMT

%%	
"const"		return(TCONST);
"else"		return(TELSE);
"if"		return(TIF);
"int"		return(TINT);
"float"		return(TFLOAT);
"char"		return(TCHAR);
"return"	return(TRETURN);
"void"		return(TVOID);
"while"		return(TWHILE);
"+"			return(TPLUS);
"-"			return(TMINUS);
"*"			return(TMULTIPLY);
"/"			return(TDIVIDE);
"%"			return(TMOD);
"="			return(TASSIGN);
"=="		return(TEQUAL);
"!="		return(TNOTEQU);
"<="		return(TLESSE);
">="		return(TGREATE);
"<"		return(TLESS);
">"		return(TGREAT);
"!"			return(TNOT);
"&&"		return(TAND);
"||"		return(TOR);
"++"		return(TINC);
"--"		return(TDEC);
"+="		return(TADDASSIGN);
"-="		return(TSUBASSIGN);
"*="		return(TMULASSIGN);
"/="		return(TDIVASSIGN);
"%="		return(TMODASSIGN);
"("			return(TLPAREN);
")"			return(TRPAREN);
","			return(TCOMMA);
";"			return(TSEMICOLON);
"["			return(TLBRACKET);
"]"			return(TRBRACKET);
"{"			return(TLBRACE);
"}"			return(TRBRACE);
[A-Za-z_][A-Za-z0-9_]*			{

								if(nextfree>=STsize){	/*다음 index가 string table의 크기를 넘는 범위에 있는 경우 overflow*/
									printf("\tError >> \tOVERFLOW!\n");
									PrintHStable();
									exit(1);
								
								}

								nextid = nextfree;
								nextfree += (yyleng+1);
								for(i = 0; i<yyleng; i++){	/*string table에 문자 한개씩 차례로 넣어줌*/
									ST[nextid+i] = yytext[i];
								}
								ComputeHS(nextid,nextfree);
								LookupHS(nextid,hashcode);

								if(!found){
									ADDHT(hashcode);
								}
								else
								{
									for(i=nextid; i<nextfree-1; i++){
										ST[i]='\0';
									
									}
									nextfree=nextid;
								}

								}return(TIDEN);
0|[1-9][0-9]*	return(TNUMBER);
0[0-7]+            return(TNUMBER); /*8진수*/
0(x|X)[0-9A-Fa-f]+      return(TNUMBER); /*16진수*/
[+-]?([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)? return(TNUMBER); /*실수*/
\"(([^\"]|\\\")*[^\\])?\"             return(TSTRING);
[0-9]+[A-Za-z_][A-Za-z0-9_]* {for(i=0;i<yyleng;i++)
									if(yytext[i] == '\n')
										cLine++;
										yyerror("scanner error : start with digit identifier\n");} /*변수가 숫자로 시작할 경우*/
[ \t]			;
"\n"			cLine++;
"//".*			;
"/*"([^*]|\*+[^*/])*\**"*/"	 {for(i=0;i<yyleng;i++)
									if(yytext[i] == '\n')
										cLine++;}	
										
[A-Za-z_]+[^A-Za-z0-9_ \n\t(){}[]]+[A-Za-z0-9_]*?	{yyerror("scanner error : illegal identifier1\n");}
[^A-Za-z0-9_ \n\t(){}[]]+[A-Za-z0-9_]*?	{yyerror("scanner error : illegal identifier2\n");}														  
.				{yyerror("scanner error : illegal identifier3\n");}
%%

int yywrap() {
	return 1;
}