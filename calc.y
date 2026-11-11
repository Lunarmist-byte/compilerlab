
%{
#include <stdio.h>
#include <stdlib.h>

int yylex();

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}
%}

%token NUM

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%
S : E '\n' {
        printf("Result = %d\n", $1);
    }
  ;

E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E {
        if($3 == 0) {
            yyerror("Division by zero");
            exit(1);
        }
        $$ = $1 / $3;
    }
  | '-' E %prec UMINUS { $$ = -$2; }
  | '(' E ')' { $$ = $2; }
  | NUM { $$ = $1; }
  ;
%%

int main() {
    printf("Enter the arithmetic expression: ");
    yyparse();
    return 0;
}
