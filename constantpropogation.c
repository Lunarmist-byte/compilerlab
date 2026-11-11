
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct statement {
    char lhs[10], rhs[20];
};

struct statement s[20];

char var[20][10], val[20][20];
int count=0;

int isconstant(char str[]) {
    int i=0;
    if(str[0]=='-') i=1;
    if(str[i]=='\0') return 0;

    for(;str[i];i++)
        if(!isdigit(str[i])) return 0;

    return 1;
}

void propagate(char rhs[]) {
    int i;
    for(i=0;i<count;i++) {
        if(strcmp(rhs,var[i])==0) {
            strcpy(rhs,val[i]);
            return;
        }
    }
}

int main() {
    int n,i,a,b,result;
    char op, temp[20];

    printf("Enter the no of statements: ");
    scanf("%d",&n);

    printf("Enter the statements:\n");

    for(i=0;i<n;i++)
        scanf("%9[^=]=%19s",s[i].lhs,s[i].rhs);

    printf("\nAfter Constant Propagation\n");

    for(i=0;i<n;i++) {
        strcpy(temp,s[i].rhs);

        for(int j=0;j<count;j++) {
            char *p=strstr(temp,var[j]);
            if(p && strcmp(temp,var[j])==0)
                strcpy(temp,val[j]);
        }

        if(sscanf(temp,"%d%c%d",&a,&op,&b)==3) {
            switch(op) {
                case '+': result=a+b; break;
                case '-': result=a-b; break;
                case '*': result=a*b; break;
                case '/':
                    if(b==0) goto print;
                    result=a/b;
                    break;
                default: goto print;
            }

            sprintf(temp,"%d",result);
        }

        print:
        strcpy(s[i].rhs,temp);

        if(isconstant(temp)) {
            strcpy(var[count],s[i].lhs);
            strcpy(val[count],temp);
            count++;
        }
    }

    for(i=0;i<n;i++)
        printf("%s=%s\n",s[i].lhs,s[i].rhs);

    return 0;
}
