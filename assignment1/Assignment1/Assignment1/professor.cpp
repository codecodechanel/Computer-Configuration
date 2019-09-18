#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "testdata2.txt"

#define STsize 100   //size of string table
#define HTsize 100   //size of hash table

#define FALSE 0
#define TRUE 1

//letter, digit, �׸��� seperator�� ���� Ư�� ���ڰ� �ش� ������ ���ϴ��� üũ�� �� ���
#define isLetter(ch) (((ch) >= 'a' && (ch) <= 'z') || ((ch) >= 'A' && (ch) <= 'Z') || (ch) == '_') 
#define isDigit(x) (((x)<='9' && (x)>='0'))
#define isSeperator(s) ((s) == ' ' | (s) == '\n' | (s) == '\t' | (s) == ';' | (s) == '.' | (s) == ',' | (s) == '?' | (s) == '!')

typedef struct HTentry *HTpointer;
typedef struct HTentry {
	int index;   //index of identifier in ST
	HTpointer next;   //pointer to next identifier
}HTentry;

//���� �� �ִ� ���� ������ ����Ÿ�Ե��� �̸� �����صд�.
enum errorTypes { noerror, illsp, illid, overst, toolong };
typedef enum errorTypes ERRORtypes;
HTpointer HT[HTsize];
char ST[STsize];

int nextid = 0;
int nextfree = 0;
int hashcode = 0;
int sameid = 0;
int found;

ERRORtypes err;

FILE *fp;
char input;

//file�� �б� ���� ������ ��, �ش� ���Ͽ��� ���� �� ���� �о���� �Լ�
void initialize() {
	fp = fopen(FILE_NAME, "r");
	input = fgetc(fp);
}

void PrintHeading() {
	printf("\n\n");
	printf("-----------------------\n");
	printf("index in ST identifier\n");
	printf("-----------------------\n");
	printf("\n");
}

//Hash Table�� ����Ǿ��� ������ ������ִ� �Լ�
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

//err�� ����� ���� ���� �ٸ� �������� ��µǵ��� ���ִ� �Լ�
void PrintError(ERRORtypes err) {
	//String table�� ũ�⺸�� �� ���� ������ ����� ���
	if (err == overst) {
		printf("...Error... OVERFLOW");
		PrintHStable();
	}
	else if (err == illsp)	//�������� seperator�� �ƴ� �ٸ� ���ڰ� �Էµ� ���
		printf("...Error... %c is illegal seperator \n", input);
	else if (err == toolong)	//������ ���̰� �ʹ� �� ���
		printf("...Error... ");
	//���� �̸��� ���ڷ� ���۵Ǵ� ���
	else if (err == illid) {
		printf("...Error... ");
		while (input != EOF && (isLetter(input) || isDigit(input)))
		{
			printf("%c", input);
			input = fgetc(fp);
		}
		printf("\tStart with digit\n");
	}
}

//seperator ���� �ԷµǴ� ��� ���� ���ڸ� �о���̴� �Լ�
void SkipSeperators() {
	while (input != EOF && !(isLetter(input) || isDigit(input)))
	{
		//������ seperator�� �ƴ� ��쿡�� ���� ��� �Լ��� ȣ��
		if (!isSeperator(input)) {
			err = illsp;
			PrintError(err);
		}
		input = fgetc(fp);
	}
}

//file�κ��� ���ڵ��� �� ���� �о�� string table�� �������ִ� �Լ�
void ReadID() {
	nextid = nextfree;
	//�о���� input���� ���ڷ� ���۵Ǵ� ��� ���� ��� �Լ��� ȣ��
	if (isDigit(input)) {
		err = illid;
		PrintError(err);
	}
	else {
		//input�� ���� �Ǵ� ������ ��� string table�� �ش� ���� �������� �� nextfree�� 1 ������Ű�� file�κ��� ���� �о�´�.(�̸� �ݺ�)
		while ((isLetter(input) || isDigit(input))) {
			//nextfree�� STsize���� �Ȱ��� ��� string table�� ���� á�ٴ� ����̹Ƿ� overflow ������ ��½�Ű���� ���� ��� �Լ��� ȣ���Ѵ�.
			if (nextfree == STsize) {
				err = overst;
				PrintError(err);
			}
			ST[nextfree] = input;
			nextfree++;
			input = fgetc(fp);
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
		here = HT[hscode];
		while (here != NULL && found == FALSE) {
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;

			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j])
					found = FALSE;
				else {
					i++;
					j++; 
				}
			}
			here = here->next;
		}
	}
}

//���� hash code���� hash table�� �������ִ� �Լ�
void ADDHT(int hscode) {
	HTpointer ptr;
	ptr = (HTpointer)malloc(sizeof(ptr));	//HTpointer�� ũ�⸸ŭ �޸� ������ �Ҵ����ش�.
	ptr->index = nextid;
	ptr->next = HT[hscode]; 
	HT[hscode] = ptr;
}


int main() {
	int i;
	PrintHeading();
	initialize();
	//������ ���� �����ϱ� ������ while�� �ݺ�
	while (input != EOF)
	{
		err = noerror;
		SkipSeperators();
		ReadID();
		//KY: EOF ���� ������ ������ ������ϵ��� ������
		//�߸��� ������ �ƴ� ���
		if (err != illid) {
			if (nextfree == STsize) {
				err = overst;
				PrintError(err);
			}
			ST[nextfree++] = '\0';
			ComputeHS(nextid, nextfree); //�о�� ���鿡 ���� hash code�� ���
			LookupHS(nextid, hashcode);	//���� hash code���� hash table�� �̹� �ִ��� Ȯ��

			//hash table�� �ش� hash code���� ���� ���
			if (!found&&ST[nextid] != NULL) {
				//������ ���̰� �ʹ� ���� ���� ���
				if ((nextfree - nextid - 1) <= 10) {
					printf("%6d      ", nextid);
					for (i = nextid; i < nextfree - 1; i++) //string table�� ����Ǿ��ִ� ������ ������ش�.
						printf("%c", ST[i]);
					printf("      (entered)\n");
					ADDHT(hashcode); //�ش� hash code�� hash table�� �������ش�.
				}
				//������ ���̰� �ʹ� �� ���
				else  if ((nextfree - nextid - 1) > 10) {
					err = toolong;
					PrintError(err); //���� ���̰� �� �Ϳ� ���� ������ ������ش�.
					for (i = nextid; i < nextfree - 1; i++)
						printf("%c", ST[i]);
					nextfree = nextid; //string table�� ������ ������� �ʵ��� nextid���� �ٽ� nextfree�� �־��ش�.
					printf("\t too long identifier\n");
				}
			}
			//hash table�� �ش� hash code���� �ִ� ���
			else if (found) {
				printf("%6d      ", sameid);
				for (i = nextid; i < nextfree - 1; i++)
					printf("%c", ST[i]);
				printf("      (already existed)\n");
				nextfree = nextid; //string table�� ������ ������� �ʵ��� nextid���� �ٽ� nextfree�� �־��ش�.
			}
		}
	}
	PrintHStable(); //��� ���� �Ϸ�� �� hash table�� ������ش�.
}