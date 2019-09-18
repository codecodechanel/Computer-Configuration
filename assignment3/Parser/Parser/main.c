#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
extern void PrintHStable();
extern yyparse();

void main()
{
	printf("=====ERROR REPORT=====\n");

	printf("=================================\n");
	cLine = 1;	//첫 번째 줄부터 읽기 시작
	cErrors = 0;	//에러는 0개부터 시작(에러를 찾을 때마다 1씩 증가)
	yyparse();
	
	if(cErrors==0)printf("\n no error\n");
	else printf(" %d error detected\n\n",cErrors);
	PrintHStable();
}

