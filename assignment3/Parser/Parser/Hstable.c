#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"


//hash code�� ������ִ� �Լ�
void ComputeHS(int nid, int nfree) {
	int func, i;
	func = 0;
	//string table�� ����Ǿ��ִ� ���� ���̸�ŭ for���� �ݺ��ϸ� ���� �����ش�.(�� ��, ����Ǿ��ִ� ���� �����̹Ƿ� ���������� �ٲ���� �Ѵ�.)
	for (i = nid; i < nfree - 1; i++)
		func += (int)ST[nid++];
	//hash code���� hash table�� ũ�⸦ ����� �ȵǹǷ� HTsize�� ���� �������� hash code�� �ִ´�.
	hashcode = func % HTsize;
}

//hash table�� �ش� hash code���� �ִ����� Ȯ�����ִ� �Լ�
void LookupHS(int nid, int hscode) {
	HTptr here;
	int i, j,k;
	int htid = 0, stid = 0;
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

			for (k = i; ST[k] != '\0'; k++) htid++;
			for (k = j; ST[k] != '\0'; k++) stid++;
			if (htid != stid) found = FALSE;

			//���� identifier���� index ����
			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j])
					found = FALSE;
				else {
					i++;
					j++;
				}
			}if (found == TRUE)return;
			//hash table ���� ĭ���� ����
			here = here->next;
		}
	}
}

//���� hash code���� hash table�� �������ִ� �Լ�
void ADDHT(int hscode) {
	HTptr tmp;

	//�ش� hashcode �� ��ġ�� �ƹ��͵� ������ ���� ���
	if (HT[hscode] == NULL) {
		tmp = (HTptr)malloc(sizeof(struct HTentry));   //HTpointer�� ũ�⸸ŭ �޸� ������ �Ҵ����ش�.
		tmp->type = 0;
		tmp->next = NULL;
		HT[hscode] = tmp;
		tmp->index = nextid;
		tmp->line = cLine;
	}
	//�ش� hashcode �� ��ġ�� htpointer�� ������ ���
	else {
		tmp = (HTptr)malloc(sizeof(struct HTentry));   //HTpointer�� ũ�⸸ŭ �޸� ������ �Ҵ����ش�.
		tmp->type = 0;
		tmp->index = nextid;
		tmp->next = HT[hscode];
		HT[hscode] = tmp;
		tmp->line = cLine;
	}
	look_id = tmp;
}
//Hash Table�� ����Ǿ��� ������ ������ִ� �Լ�
void PrintHStable() {
	int i, j;
	HTptr here;
	printf("\n\n\n\n[[HASH TABLE]]\n\n");

	//Hash Table�� ũ�⸸ŭ �ݺ�
	for (i = 0; i < HTsize; i++)
		if (HT[i] != NULL) {

			here = HT[i];
			//Hash Table���� here�� NULL�� �� ������ here->next�� ���� �������� ��� �ݺ�
			for (here = HT[i]; here != NULL; here = here->next) {
				//j = here->index;
				//String table���� �� ĭ�� ���� ������ ����Ǿ��ִ� ���ڰ����� �����.
				printf("HASH CODE %4d: (", i);
				for (j = here->index; ST[j] != '\0';j++) {
					printf("%c", ST[j]);
				}
				printf(" : ");
				//���� ����ġ
				switch (here->type)
				{
				case 1:		//���� ����� ���� ������ ���
					printf("integer scalar var");	
					printf(", line%d )\n", here->line);
					break;
				case 2:		//�Ǽ� ����� ���� ������ ��� 
					printf("float scalar var"); 
					printf(", line%d )\n", here->line);
					break;
				case 3:		//���� �迭�� ���� ������ ��� 
					printf("array integer var"); 
					printf(", line%d )\n", here->line);
					break;
				case 4:		//������ ���ڷ� ��ȯ�ϴ� �Լ��� ��� 
					printf("function name, return type = int");
					printf(", line%d )\n", here->line);
					break;
				case 5:		//���ǵ��� ���� ���� �Ǵ� �Լ��� ��� 
					printf("not defined id/func"); 
					printf(", line%d )\n", here->line);
					break;
				case 6:		//��ȯ�ϴ� ���ڰ� ���� �Լ��� ���
					printf("function name, return type = void");
					printf(", line%d )\n", here->line);
					break;
				case 7:		//�Ǽ��� ���ڷ� ��ȯ�ϴ� �Լ��� ���
					printf("function name, return type = float");
					printf(", line%d )\n", here->line);
					break;
				case 8:		//���ڸ� ���ڷ� ��ȯ�ϴ� �Լ��� ���
					printf("function name, return type = char");
					printf(", line%d )\n", here->line);
					break;
				case 9:		//���ڿ� ���� ������ ���
					printf("char scalar var");
					printf(", line%d )\n", here->line);
					break;
				case 10:		//�Ǽ� �迭�� ���� ������ ���
					printf("array float var");
					printf(", line%d )\n", here->line);
					break;
				case 11:		//���� �迭�� ���� ������ ���
					printf("array char var");
					printf(", line%d )\n", here->line);
					break;
				default:		//����
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