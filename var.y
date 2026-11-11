%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s) { printf("Invalid Variable Name!\n"); exit(0); }
%}
%token LETTER DIGIT
%%
S  : ID '\n' { printf("Valid Variable Name!\n"); exit(0); } ;
ID : LETTER
   | ID LETTER
   | ID DIGIT
   ;
%%
int main() {
    printf("Enter variable name: ");
    yyparse();
    return 0;
}
