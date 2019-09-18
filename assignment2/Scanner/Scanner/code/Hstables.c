/*
Hstable.c- �ĺ��ڷ� �νĵ� ��ū�� �������ִ� �ؽ����̺� ���� �Լ���
programmer-�̰濬, �ڼ���
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



//file�κ��� ���ڵ��� �� ���� �о�� string table�� �������ִ� �Լ�
void ReadID() {
	nextid = nextfree;
	//�о���� input���� ���ڷ� ���۵Ǵ� ��� ���� ��� �Լ��� ȣ��
	if (isDigit(input_char)) {

	}
	else {
		//input�� ���� �Ǵ� ������ ��� string table�� �ش� ���� �������� �� nextfree�� 1 ������Ű�� file�κ��� ���� �о�´�.(�̸� �ݺ�)
		while ((isLetter(input_char) || isDigit(input_char))) {
			//nextfree�� STsize���� �Ȱ��� ��� string table�� ���� á�ٴ� ����̹Ƿ� overflow ������ ��½�Ű���� ���� ��� �Լ��� ȣ���Ѵ�.
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


//hash code�� ������ִ� �Լ�
void ComputeHS(int nid, int nfree) {
	int code, i;
	code = 0;
	//string table�� ����Ǿ��ִ� ���� ���̸�ŭ for���� �ݺ��ϸ� ���� �����ش�.(�� ��, ����Ǿ��ִ� ���� �����̹Ƿ� ���������� �ٲ���� �Ѵ�.)
	for (i = nid; i < nfree - 1; i++)
		code += (int)ST[i];
	//hash code���� hash table�� ũ�⸦ ����� �ȵǹǷ� HTsize�� ���� �������� hash code�� �ִ´�.
	hashcode = code % HTsize;
}

//hash table�� �ش� hash code���� �ִ����� Ȯ�����ִ� �Լ�
void LookupHS(int nid, int hscode) {
	HTpointer here;
	int i, j;
	found = FALSE; //found�� ���� FALSE�� �ʱ�ȭ�����ش�.

				   //hash table���� hash code ���� ���� ���
	if (HT[hscode] != NULL) {
		//hash table�� here ������ ��ġ
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;

			//���� identifier���� index ����
			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j])
					found = FALSE;
				else {
					i++;
					j++;
				}
			}
			//hash table ���� ĭ���� ����
			here = here->next;
		}
	}
}

//���� hash code���� hash table�� �������ִ� �Լ�
void ADDHT(int hscode) {
	HTpointer ptr;
	ptr = (HTpointer)malloc(sizeof(ptr));   //HTpointer�� ũ�⸸ŭ �޸� ������ �Ҵ����ش�.
	ptr->index = nextid;
	ptr->next = HT[hscode];
	HT[hscode] = ptr;
}

//�Ⱦ����� �׽�Ʈ��]Hash Table�� ����Ǿ��� ������ ������ִ� �Լ�
void PrintHStable() {
	int i, j;
	HTpointer here;
	printf("\n\n\n\n[[HASH TABLE]]\n\n");

	//Hash Table�� ũ�⸸ŭ �ݺ�
	for (i = 0; i < HTsize; i++)
		if (HT[i] != NULL) {
			printf("HASH CODE %d : ", i);
			//Hash Table���� here�� NULL�� �� ������ here->next�� ���� �������� ��� �ݺ�
			for (here = HT[i]; here != NULL; here = here->next) {
				j = here->index;
				//String table���� �� ĭ�� ���� ������ ����Ǿ��ִ� ���ڰ����� �����.
				while (j < STsize && ST[j] != '\0') {
					printf("%c", ST[j++]);
				}
				printf("   ");
			}
			printf("\n");
		}
	printf("\n\n\n <%5d characters are used in the string table > \n", nextfree);
}

