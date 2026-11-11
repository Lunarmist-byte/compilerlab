
#include<stdio.h>
#include<string.h>

int main() {
    int n,i;
    char lhs[20],rhs[30];
    char arg1[20],arg2[20],op;

    printf("Enter the number of TAC statements: ");
    scanf("%d",&n);

    printf("Enter the TAC statements:\n");

    for(i=0;i<n;i++) {
        scanf("%19[^=]=%29s",lhs,rhs);
        getchar();

        int j;
        for(j=0;rhs[j];j++) {
            if(rhs[j]=='+' || rhs[j]=='-' ||
               rhs[j]=='*' || rhs[j]=='/')
                break;
        }

        printf("\n");

        if(rhs[j]!='\0') {
            op=rhs[j];
            rhs[j]='\0';

            strcpy(arg1,rhs);
            strcpy(arg2,rhs+j+1);

            printf("MOV AX,%s\n",arg1);

            switch(op) {
                case '+': printf("ADD AX,%s\n",arg2); break;
                case '-': printf("SUB AX,%s\n",arg2); break;
                case '*': printf("MUL %s\n",arg2); break;
                case '/': printf("DIV %s\n",arg2); break;
            }

            printf("MOV %s,AX\n",lhs);
        }
        else {
            printf("MOV AX,%s\n",rhs);
            printf("MOV %s,AX\n",lhs);
        }
    }

    return 0;
}
