%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token TYPE ID NUM

%%
stmt: TYPE ID '[' NUM ']' ';'
{
	printf("\nvalid\n");
}
;
%%

int main()
{
	printf("Enter your declaration : ");
	yyparse();
	return 0;
}
void yyerror(const char *s)
{
	printf("\nInvalid\n");
}
