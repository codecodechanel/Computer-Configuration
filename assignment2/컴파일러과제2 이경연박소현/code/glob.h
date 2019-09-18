#pragma once
/*
glob.h- 프로젝트에 필요한 글로벌 변수를 선언
programmer-이경연, 박소현
date-19.04.26
*/

#define STsize 300  //size of string table
#define HTsize 100   //size of hash table

#define FALSE 0
#define TRUE 1

//letter, digit, 그리고 seperator에 대해 특정 문자가 해당 변수에 속하는지 체크할 때 사용
#define isLetter(ch) (((ch) >= 'a' && (ch) <= 'z') || ((ch) >= 'A' && (ch) <= 'Z') || (ch) == '_') 
#define isDigit(x) (((x)<='9' && (x)>='0'))
#define isSeperator(s) ((s) == ' ' | (s) == '\n' | (s) == '\t' | (s) == ';' | (s) == '.' | (s) == ',' | (s) == '?' | (s) == '!')

typedef struct HTentry *HTpointer;
typedef struct HTentry {
	int index;   //index of identifier in ST
	HTpointer next;   //pointer to next identifier
}HTentry;
//나올 수 있는 여러 종류의 에러타입들을 미리 지정해둔다.
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