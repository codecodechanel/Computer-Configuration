#include  <stdio.h>
#include "tn.h"

extern int yyparse();

void main()
{
	printf("Start of Parser\n");
	yyparse() ;
}
