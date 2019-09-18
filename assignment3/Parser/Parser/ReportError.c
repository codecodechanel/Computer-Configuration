#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
extern void line(int);
//extern  void yylex();

yyerror(s) 
char *s;
{
	if (strcmp("parse error", s)) {
		line(cLine);
		printf("< Scanner Error > => %s\n", s);
		cErrors++;
	}
}

//에러 종류에 따라 알맞는 문구 출력
void printError(ERRORtypes err) {
	switch (err)
	{
	case 0:
		line(cLine);
		printf("< Error > => Wrong Statement!\n");	//잘못된 문장일 경우
		cErrors++;
		break;
	case 1:
		line(cLine);
		printf("< Error > => Missing semicolon\n");	//세미콜론(;)이 없는 경우
		cErrors++;
		break;
	case 2:
		line(cLine);
		printf("< Error > => Missing brace\n");		//'}'가 없는 경우
		cErrors++;
		break;
	case 3:
		line(cLine);
		printf("< Error > => Missing bracket\n");	//']'가 없는 경우
		cErrors++;
		break;
	case 4:
		line(cLine);
		printf("< Error > => Missing parenthesis\n");//')'가 없는 경우
		cErrors++;
		break;
	case 5:
		line(cLine);
		printf("< Error > => Missing comma\n");		//','가 없는 경우
		cErrors++;
		break;
	case 6:
		line(cLine);
		printf("< Error > => Missing function name\n");	//함수에 이름이 정의되지 않은 경우
		cErrors++;
		break;
	case 7:
		line(cLine);
		printf("< Error > => Assign Error\n");	//잘못된 방식으로 assign할 경우(ex] 0=i)
		cErrors++;
		break;
	case 8:
		line(cLine);
		printf("< Error > => wrong func def\n");	//함수를 잘못 정의한 경우
		cErrors++;
		break;
	case 9:
		line(cLine);
		printf("< Error > => no func param\n");	//함수 파라미터가 지정되지 않은 경우
		cErrors++;
		break;
	}
}