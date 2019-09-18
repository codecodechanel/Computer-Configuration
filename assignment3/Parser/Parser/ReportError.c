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

//���� ������ ���� �˸´� ���� ���
void printError(ERRORtypes err) {
	switch (err)
	{
	case 0:
		line(cLine);
		printf("< Error > => Wrong Statement!\n");	//�߸��� ������ ���
		cErrors++;
		break;
	case 1:
		line(cLine);
		printf("< Error > => Missing semicolon\n");	//�����ݷ�(;)�� ���� ���
		cErrors++;
		break;
	case 2:
		line(cLine);
		printf("< Error > => Missing brace\n");		//'}'�� ���� ���
		cErrors++;
		break;
	case 3:
		line(cLine);
		printf("< Error > => Missing bracket\n");	//']'�� ���� ���
		cErrors++;
		break;
	case 4:
		line(cLine);
		printf("< Error > => Missing parenthesis\n");//')'�� ���� ���
		cErrors++;
		break;
	case 5:
		line(cLine);
		printf("< Error > => Missing comma\n");		//','�� ���� ���
		cErrors++;
		break;
	case 6:
		line(cLine);
		printf("< Error > => Missing function name\n");	//�Լ��� �̸��� ���ǵ��� ���� ���
		cErrors++;
		break;
	case 7:
		line(cLine);
		printf("< Error > => Assign Error\n");	//�߸��� ������� assign�� ���(ex] 0=i)
		cErrors++;
		break;
	case 8:
		line(cLine);
		printf("< Error > => wrong func def\n");	//�Լ��� �߸� ������ ���
		cErrors++;
		break;
	case 9:
		line(cLine);
		printf("< Error > => no func param\n");	//�Լ� �Ķ���Ͱ� �������� ���� ���
		cErrors++;
		break;
	}
}