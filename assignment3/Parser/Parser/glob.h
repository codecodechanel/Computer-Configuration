#pragma once
/*
glob.h- global variable for the prject
programmer-
date-
*/

#define STsize 1000   //size of string table
#define HTsize 100   //size of hash table
#define FALSE 0
#define TRUE 1


typedef struct HTentry *HTptr;
typedef struct HTentry {
	int index;   //index of identifier in ST
	int type;
	int line;
	HTptr next;   //pointer to next identifier
}HTentry;

HTptr HT[HTsize];
char ST[STsize];

int nextid;
int nextfree;
int hashcode;
int sameid;

//나올 수 있는 여러 종류의 에러타입들을 미리 지정해둔다.
enum errorTypes { wrong_st, nosemi, nobrace, nobracket, noparen, nocomma, nofuncname , assignerr, wrong_funcdef, nofuncparam
};
typedef enum errorTypes ERRORtypes;
ERRORtypes err;

int cLine;
int cErrors;

int found;
HTptr look_id;
HTptr look_tmp;
