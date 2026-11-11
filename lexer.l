
%{
#include <stdio.h>
int line = 1;
%}

%%
\n                                          { line++; }
[ \t]+                                      ;
"#".*                                       ;
"//".*                                      ;
"/*"([^*]|\*+[^*/])*\*+"/"                  ;

"int"|"float"|"char"|"if"|"else"|"while"|"for"|"return"|"void"
                                            { printf("Line %d: KEYWORD\t\t%s\n", line, yytext); }

[a-zA-Z_][a-zA-Z0-9_]*                      { printf("Line %d: IDENTIFIER\t%s\n", line, yytext); }

[0-9]+(\.[0-9]+)?                           { printf("Line %d: NUMBER\t\t%s\n", line, yytext); }

\"[^\"\n]*\"                                { printf("Line %d: STRING\t\t%s\n", line, yytext); }

"=="|"!="|"<="|">="|"<"|">"                 { printf("Line %d: RELATIONAL OP\t%s\n", line, yytext); }

"="                                         { printf("Line %d: ASSIGNMENT OP\t%s\n", line, yytext); }

"+"|"-"|"*"|"/"|"%"                         { printf("Line %d: ARITHMETIC OP\t%s\n", line, yytext); }

[;,(){}\[\]]                                { printf("Line %d: SPECIAL SYMBOL\t%s\n", line, yytext); }

.                                           { printf("Line %d: UNKNOWN\t\t%s\n", line, yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("input.c", "r");

    if (!yyin) {
        printf("Create input.c first!\n");
        return 1;
    }

    yylex();
    fclose(yyin);

    return 0;
}
