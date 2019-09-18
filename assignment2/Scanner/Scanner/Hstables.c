/*
Hstable.c- 식별자로 인식된 토큰을 관리해주는 해시테이블 관련 함수들
programmer-이경연, 박소현
date-19.04.26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"

void PrintHeading() {
	printf("\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("Line number\t        Token type\t                        Token                          ST-index\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
}



//file로부터 문자들을 한 개씩 읽어와 string table에 저장해주는 함수
void ReadID() {
	nextid = nextfree;
	//읽어들인 input값이 숫자로 시작되는 경우 에러 출력 함수를 호출
	if (isDigit(input_char)) {

	}
	else {
		//input이 문자 또는 숫자일 경우 string table에 해당 값을 저장해준 뒤 nextfree를 1 증가시키고 file로부터 새로 읽어온다.(이를 반복)
		while ((isLetter(input_char) || isDigit(input_char))) {
			//nextfree가 STsize값과 똑같을 경우 string table이 가득 찼다는 얘기이므로 overflow 에러를 출력시키도록 에러 출력 함수를 호출한다.
			if (nextfree == STsize) {
				err = overst;
				PrintError(err);
			}
			ST[nextfree] = input_char;
			nextfree++;
			indexyy++;
			input_char = yytext_for_ht[indexyy];
		}
	}
}


//hash code를 계산해주는 함수
void ComputeHS(int nid, int nfree) {
	int code, i;
	code = 0;
	//string table에 저장되어있는 변수 길이만큼 for문을 반복하며 값을 더해준다.(이 때, 저장되어있는 값은 문자이므로 정수값으로 바꿔줘야 한다.)
	for (i = nid; i < nfree - 1; i++)
		code += (int)ST[i];
	//hash code값이 hash table의 크기를 벗어나면 안되므로 HTsize를 나눈 나머지를 hash code로 넣는다.
	hashcode = code % HTsize;
}

//hash table에 해당 hash code값이 있는지를 확인해주는 함수
void LookupHS(int nid, int hscode) {
	HTpointer here;
	int i, j;
	found = FALSE; //found를 먼저 FALSE로 초기화시켜준다.

				   //hash table에서 hash code 값이 있을 경우
	if (HT[hscode] != NULL) {
		//hash table에 here 포인터 배치
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;

			//다음 identifier까지 index 조정
			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j])
					found = FALSE;
				else {
					i++;
					j++;
				}
			}
			//hash table 다음 칸으로 조정
			here = here->next;
		}
	}
}

//계산된 hash code값을 hash table에 저장해주는 함수
void ADDHT(int hscode) {
	HTpointer ptr;
	ptr = (HTpointer)malloc(sizeof(ptr));   //HTpointer의 크기만큼 메모리 공간을 할당해준다.
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}

//안쓰지만 테스트용]Hash Table에 저장되어진 값들을 출력해주는 함수
void PrintHStable() {
	int i, j;
	HTpointer here;
	printf("\n\n\n\n[[HASH TABLE]]\n\n");

	//Hash Table의 크기만큼 반복
	for (i = 0; i < HTsize; i++)
		if (HT[i] != NULL) {
			printf("HASH CODE %d : ", i);
			//Hash Table에서 here가 NULL이 될 때까지 here->next를 통해 다음으로 계속 반복
			for (here = HT[i]; here != NULL; here = here->next) {
				j = here->index;
				//String table에서 빈 칸이 나올 때까지 저장되어있는 문자값들을 출력함.
				while (j < STsize && ST[j] != '\0') {
					printf("%c", ST[j++]);
				}
				printf("   ");
			}
			printf("\n");
		}
	printf("\n\n\n <%5d characters are used in the string table > \n", nextfree);
}

