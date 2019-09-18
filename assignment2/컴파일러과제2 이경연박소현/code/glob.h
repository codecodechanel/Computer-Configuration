#pragma once
/*
glob.h- ������Ʈ�� �ʿ��� �۷ι� ������ ����
programmer-�̰濬, �ڼ���
date-19.04.26
*/

#define STsize 300  //size of string table
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

void PrintError(ERRORtypes err);
void PrintHeading();
void PrintHStable();
void ComputeHS(int nid, int nfree);
void LookupHS(int nid, int hscode);
void ADDHT(int hscode);

int nextid ;
int nextfree ;
int hashcode ;
int sameid ;
int found;

ERRORtypes err;
int line_num;

char *yytext_for_ht;
char input_char;
int indexyy;
int leng;