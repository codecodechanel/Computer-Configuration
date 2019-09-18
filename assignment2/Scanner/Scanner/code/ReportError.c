/*
PrintError.c- 오류라고 인식된 토큰을 출력할때 어떤 에러메시지를 남길지 관리한다.
programmer-이경연, 박소현
date-19.04.26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"



//err에 저장된 값에 따라 다른 에러문이 출력되도록 해주는 함수
void PrintError(ERRORtypes err) {
	//String table의 크기보다 더 많은 값들이 저장된 경우
	if (err == overst) {
		printf("...Error... OVERFLOW");
		//		PrintHStable();
	}
	else if (err == toolong)   //변수의 길이가 너무 긴 경우
		printf("...Error...  too long");
	//변수 이름이 숫자로 시작되는 경우
	else if (err == illid) {
		printf("...Error... Start with digit");
	}
	//정의되지않은 문자가 나올 경우
	else if (err == illsp) {
		printf("...Error... illegal char");
	}
}
