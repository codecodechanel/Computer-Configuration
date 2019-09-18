#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"


//hash code를 계산해주는 함수
void ComputeHS(int nid, int nfree) {
	int func, i;
	func = 0;
	//string table에 저장되어있는 변수 길이만큼 for문을 반복하며 값을 더해준다.(이 때, 저장되어있는 값은 문자이므로 정수값으로 바꿔줘야 한다.)
	for (i = nid; i < nfree - 1; i++)
		func += (int)ST[nid++];
	//hash code값이 hash table의 크기를 벗어나면 안되므로 HTsize를 나눈 나머지를 hash code로 넣는다.
	hashcode = func % HTsize;
}

//hash table에 해당 hash code값이 있는지를 확인해주는 함수
void LookupHS(int nid, int hscode) {
	HTptr here;
	int i, j,k;
	int htid = 0, stid = 0;
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

			for (k = i; ST[k] != '\0'; k++) htid++;
			for (k = j; ST[k] != '\0'; k++) stid++;
			if (htid != stid) found = FALSE;

			//다음 identifier까지 index 조정
			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j])
					found = FALSE;
				else {
					i++;
					j++;
				}
			}if (found == TRUE)return;
			//hash table 다음 칸으로 조정
			here = here->next;
		}
	}
}

//계산된 hash code값을 hash table에 저장해주는 함수
void ADDHT(int hscode) {
	HTptr tmp;

	//해당 hashcode 값 위치에 아무것도 들어가있지 않은 경우
	if (HT[hscode] == NULL) {
		tmp = (HTptr)malloc(sizeof(struct HTentry));   //HTpointer의 크기만큼 메모리 공간을 할당해준다.
		tmp->type = 0;
		tmp->next = NULL;
		HT[hscode] = tmp;
		tmp->index = nextid;
		tmp->line = cLine;
	}
	//해당 hashcode 값 위치에 htpointer가 들어가있을 경우
	else {
		tmp = (HTptr)malloc(sizeof(struct HTentry));   //HTpointer의 크기만큼 메모리 공간을 할당해준다.
		tmp->type = 0;
		tmp->index = nextid;
		tmp->next = HT[hscode];
		HT[hscode] = tmp;
		tmp->line = cLine;
	}
	look_id = tmp;
}
//Hash Table에 저장되어진 값들을 출력해주는 함수
void PrintHStable() {
	int i, j;
	HTptr here;
	printf("\n\n\n\n[[HASH TABLE]]\n\n");

	//Hash Table의 크기만큼 반복
	for (i = 0; i < HTsize; i++)
		if (HT[i] != NULL) {

			here = HT[i];
			//Hash Table에서 here가 NULL이 될 때까지 here->next를 통해 다음으로 계속 반복
			for (here = HT[i]; here != NULL; here = here->next) {
				//j = here->index;
				//String table에서 빈 칸이 나올 때까지 저장되어있는 문자값들을 출력함.
				printf("HASH CODE %4d: (", i);
				for (j = here->index; ST[j] != '\0';j++) {
					printf("%c", ST[j]);
				}
				printf(" : ");
				//여기 스위치
				switch (here->type)
				{
				case 1:		//정수 상수에 대한 변수일 경우
					printf("integer scalar var");	
					printf(", line%d )\n", here->line);
					break;
				case 2:		//실수 상수에 대한 변수일 경우 
					printf("float scalar var"); 
					printf(", line%d )\n", here->line);
					break;
				case 3:		//정수 배열에 대한 변수일 경우 
					printf("array integer var"); 
					printf(", line%d )\n", here->line);
					break;
				case 4:		//정수를 인자로 반환하는 함수일 경우 
					printf("function name, return type = int");
					printf(", line%d )\n", here->line);
					break;
				case 5:		//정의되지 않은 변수 또는 함수일 경우 
					printf("not defined id/func"); 
					printf(", line%d )\n", here->line);
					break;
				case 6:		//반환하는 인자가 없는 함수일 경우
					printf("function name, return type = void");
					printf(", line%d )\n", here->line);
					break;
				case 7:		//실수를 인자로 반환하는 함수일 경우
					printf("function name, return type = float");
					printf(", line%d )\n", here->line);
					break;
				case 8:		//문자를 인자로 반환하는 함수일 경우
					printf("function name, return type = char");
					printf(", line%d )\n", here->line);
					break;
				case 9:		//문자에 대한 변수일 경우
					printf("char scalar var");
					printf(", line%d )\n", here->line);
					break;
				case 10:		//실수 배열에 대한 변수일 경우
					printf("array float var");
					printf(", line%d )\n", here->line);
					break;
				case 11:		//문자 배열에 대한 변수일 경우
					printf("array char var");
					printf(", line%d )\n", here->line);
					break;
				default:		//에러
					printf("id about parse err");
					printf(", line%d )\n", here->line);
					break;
				}

//				printf("   ");
			}
			printf("\n");
		}
	printf("\n\n\n <%5d characters are used in the string table > \n", nextfree);
}