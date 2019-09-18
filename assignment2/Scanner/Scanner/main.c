/*
main.c-렉스로 부터 받은 토큰들을 케이스에 따라 다르게 출력하고, 식별자는 해시테이블 작업을 수행한다.
programmer-이경연, 박소현
date-19.04.26
*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

//식별자로 인식된 종류의 토큰을 처리하는 함수이다.
//식별자들은 ST을 거쳐 Hstable에 저장한다
void iden_handler(char * yt) {
	int i;
	yytext_for_ht = yt;
	input_char = yt[indexyy];
	leng = strlen(yt);
	ReadID();
	err = noerror;
	if (err == noerror) {
		if (nextfree == STsize) {
			err = overst;
			PrintError(err);
		}
		ST[nextfree++] = '\0';
		ComputeHS(nextid, nextfree); //읽어온 값들에 대해 hash code를 계산
		LookupHS(nextid, hashcode);   //계산된 hash code값이 hash table에 이미 있는지 확인

									  //hash table에 해당 hash code값이 없을 경우
		if (!found&&ST[nextid] != NULL) {
			//변수의 길이가 너무 길지 않을 경우
			if ((nextfree - nextid - 1) <= 10) {
				ADDHT(hashcode); //해당 hash code를 hash table에 저장해준다.
			}
			//변수의 길이가 너무 길 경우
			else  if ((nextfree - nextid - 1) > 10) {
				nextfree = nextid; //string table에 변수가 저장되지 않도록 nextid값을 다시 nextfree에 넣어준다.
			}
		}
		//hash table에 해당 hash code값이 있는 경우
		else if (found) {
			nextfree = nextid; //string table에 변수가 저장되지 않도록 nextid값을 다시 nextfree에 넣어준다.
		}
	}


}




//lex로부터 나온 토큰의 종류에 따라 출력을 다르게한다.
//에러가 날 경우 PrintError.c를 통해 에러를 구분해 출력한다.
void main()
{
	PrintHeading();
	int linenum = 1;
	int base;
	int value;
	char * yt;
	enum tokentypes tn;  // token number
	extern char *yytext;
	while ((tn = yylex()) != TEOF) {
		//printf("Line number= %d\t", linenum);
		PrintError(noerror);
		switch (tn) {

			//예약어
		case TCONST: printf("%d                TCONST                %22s\n", linenum, yytext); break;
		case TELSE: printf("%d                  TELSE                  %22s\n", linenum, yytext); break;
		case TIF: printf("%d                  TIF                  %22s\n", linenum, yytext); break;
		case TINT: printf("%d                  TINT                  %22s\n", linenum, yytext); break;
		case TRETURN: printf("%d                  TRETURN                  %22s\n", linenum, yytext); break;
		case TVOID: printf("%d                  TVOID                  %22s\n", linenum, yytext); break;
		case TWHILE: printf("%d                  TWHILE                 %22s\n", linenum, yytext); break;

			//사칙연산자
		case TPLUS: printf("%d                  TPLUS                 %22s\n", linenum, yytext); break;
		case TMINUS: printf("%d                  TMINUX                 %22s\n", linenum, yytext); break;
		case TMUL: printf("%d                  TMUL                 %22s\n", linenum, yytext); break;
		case TDIV: printf("%d                  TDIV                 %22s\n", linenum, yytext); break;
		case TPERCENT: printf("%d                  TPERCENT                 %22s\n", linenum, yytext); break;
			//배정연산자
		case TADDASSIGN: printf("%d                  TADDASSIGN                  %16s\n", linenum, yytext); break;
		case TSUBASSIGN: printf("%d                  TSUBASSIGN                  %16s\n", linenum, yytext); break;
		case TMULASSIGN: printf("%d                  TMULASSIGN                  %16s\n", linenum, yytext); break;
		case TDIVASSIGN: printf("%d                  TDIVASSIGN                  %16s\n", linenum, yytext); break;
		case TMODASSIGN: printf("%d                  TMODASSIGN                  %16s\n", linenum, yytext); break;
		case TASSIGN: printf("%d                  TASSIGN                  %16s\n", linenum, yytext); break;

			//논리연산자
		case TNOT: printf("%d                  TNOT                  %21s\n", linenum, yytext); break;
		case TAND: printf("%d                  TAND                  %21s\n", linenum, yytext); break;
		case TOR: printf("%d                  TOR                   %21s\n", linenum, yytext); break;

			//관계연산자
		case TEQUAL: printf("%d                  TEQUAL                   %19s\n", linenum, yytext); break;
		case TNOTEQU: printf("%d                  TNOTEQU                  %19s\n", linenum, yytext); break;
		case TLESS: printf("%d                  TLESS                   %19s\n", linenum, yytext); break;
		case TGREAT: printf("%d                  TGREAT                   %19s\n", linenum, yytext); break;
		case TEQLESS: printf("%d                  TEQLESS                   %19s\n", linenum, yytext); break;
		case TEQGREAT: printf("%d                  TEQGREAT                   %19s\n", linenum, yytext); break;
			//증감연산자		
		case TINC: printf("%d                  TINC                   %21s\n", linenum, yytext); break;
		case TDEC: printf("%d                  TDEC                   %21s\n", linenum, yytext); break;

			//Identifier
		case TIDENT:
			printf("%d                  TIDENT                   %18s                        %d\n", linenum, yytext, nextfree);
			yt = yytext;  iden_handler(yt); indexyy = 0;  break;
			//스트링과 캐릭터
		case TSTRING:printf("%d                  TSTRING                   %18s\n", linenum, yytext); break;
		case TCHAR:printf("%d                  TCHAR                   %18s\n", linenum, yytext); break;


			//특수기호
		case TSMALLBRACE_L: printf("%d                  TSAMLL_L                   %18s\n", linenum, yytext); break;
		case TSMALLBRACE_R: printf("%d                  TSMALL_R                   %18s\n", linenum, yytext); break;
		case TBIGBRACE_L: printf("%d                  TLARGE_L                   %18s\n", linenum, yytext); break;
		case TBIGBRACE_R: printf("%d                  TLARGE_R                   %18s\n", linenum, yytext); break;
		case TMIDBRACE_L: printf("%d                  TMID_L                   %18s\n", linenum, yytext); break;
		case TMIDBRACE_R: printf("%d                  TMID_R                   %18s\n", linenum, yytext); break;
		case TCOLON: printf("%d                  TCOLON                   %18s\n", linenum, yytext); break;
		case TSEMICOLON: printf("%d                  TSEMICOLON                   %18s\n", linenum, yytext); break;





			//WHITE SPACE
		case TBLANK: printf("%d                  TBLANK                   %18s\n", linenum, yytext); break;
		case TTAB: printf("%d                  TTAB                   %18s\n", linenum, yytext); break;
		case TNEWLINE: linenum++; break;



			/*여기부터 따로 정의한 토큰*/

			//ERROR
		case TERROR:PrintError(illsp); printf("\tline number[%d]     =>  %s\n", linenum, yytext); break;
		case TERROR_DIGIT_START: PrintError(illid); printf("\tline number[%d]     =>  %s\n", linenum, yytext); break;
		case TERROR_ILL_CHAR_1: PrintError(illsp); printf("\tline number[%d]     =>  %s\n", linenum, yytext); break;
		case TERROR_ILL_CHAR_2: PrintError(illsp); printf("\tline number[%d]     =>  %s\n", linenum, yytext); break;
		case TLONGERR: PrintError(toolong); printf("\tline number[%d]     =>  %s\n", linenum, yytext); break;

			//수
		case TREAL: printf("%d                  TREAL                   %18s\n", linenum, yytext); break;
		case TNUMBER: printf("%d                  TNUMBER                   %18s\n", linenum, yytext); break;
		case TOCTA:
			base = 1;
			value = 0;
			for (int i = strlen(yytext) - 1; i >= 0; i--) {
				value += (yytext[i] - 48) * base;
				base = base * 8;
			}
			printf("%d                  TOCTA                   %18d\n", linenum, value); break;
		case THEXA:
			base = 1;
			value = 0;
			for (int i = strlen(yytext) - 1; i >= 0; i--) {
				if (yytext[i] >= '0' && yytext[i] <= '9') {
					value += (yytext[i] - 48) * base;
					base = base * 16;
				}
				else if (yytext[i] >= 'A' && yytext[i] <= 'F') {
					value += (yytext[i] - 55) * base;
					base = base * 16;
				}
			}
			printf("%d                  THEXA                   %18d\n", linenum, value); break;
		}
	}
	//PrintHStable();
}
