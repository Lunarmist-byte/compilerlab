
%{
#include<stdio.h>
int line=1;
%}

%%
\n                  { line++; }
[ \t]+              ;
"int"|"float"|"char"|"if"|"else"|"while"|"return"
                    { printf("KEYWORD: %s\n",yytext); }

[a-zA-Z][a-zA-Z0-9]*
                    { printf("IDENTIFIER: %s\n",yytext); }

[0-9]+              { printf("NUMBER: %s\n",yytext); }

"="                 { printf("ASSIGNMENT OPERATOR: %s\n",yytext); }

"+"|"-"|"*"|"/"     { printf("ARITHMETIC OPERATOR: %s\n",yytext); }

"<"|">"|"=="|"!="   { printf("RELATIONAL OPERATOR: %s\n",yytext); }

";"|","|"("|")"|"{"|"}"
                    { printf("SPECIAL SYMBOL: %s\n",yytext); }

.                   { printf("UNKNOWN: %s\n",yytext); }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
