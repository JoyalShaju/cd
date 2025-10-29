%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token ID NUM

%%
stmt : ID '(' arg_list ')' ';'   { printf("Valid function call syntax\n"); }
     ;

arg_list : ID
         | NUM
         | ID ',' arg_list
         | NUM ',' arg_list
         | /* empty */           /* function with no arguments */
         ;
%%

void yyerror(const char *s) {
    printf("Invalid function call syntax\n");
}

int main() {
    printf("Enter a function call: ");
    yyparse();
    return 0;
}

