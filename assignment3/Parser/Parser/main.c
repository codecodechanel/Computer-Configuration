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
	cLine = 1;	//ù ��° �ٺ��� �б� ����
	cErrors = 0;	//������ 0������ ����(������ ã�� ������ 1�� ����)
	yyparse();
	
	if(cErrors==0)printf("\n no error\n");
	else printf(" %d error detected\n\n",cErrors);
	PrintHStable();
}

