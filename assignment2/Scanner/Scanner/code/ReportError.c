/*
PrintError.c- ������� �νĵ� ��ū�� ����Ҷ� � �����޽����� ������ �����Ѵ�.
programmer-�̰濬, �ڼ���
date-19.04.26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"



//err�� ����� ���� ���� �ٸ� �������� ��µǵ��� ���ִ� �Լ�
void PrintError(ERRORtypes err) {
	//String table�� ũ�⺸�� �� ���� ������ ����� ���
	if (err == overst) {
		printf("...Error... OVERFLOW");
		//		PrintHStable();
	}
	else if (err == toolong)   //������ ���̰� �ʹ� �� ���
		printf("...Error...  too long");
	//���� �̸��� ���ڷ� ���۵Ǵ� ���
	else if (err == illid) {
		printf("...Error... Start with digit");
	}
	//���ǵ������� ���ڰ� ���� ���
	else if (err == illsp) {
		printf("...Error... illegal char");
	}
}
