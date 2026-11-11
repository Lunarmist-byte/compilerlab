
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct statement{
    char lhs[10];
    char rhs[20];
};

struct statement s[20];

int isconstant(char str[]){
    int i=0;

    if(str[i]=='-')
        i=1;

    if(str[i]=='\0')
        return 0;

    for(;str[i]!='\0';i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main(){
    int n,i,j;
    char value[20];

    printf("Enter the no of statements: ");
    scanf("%d",&n);

    printf("Enter the statements:\n");

    for(i=0;i<n;i++)
        scanf("%9[^=]=%19s",s[i].lhs,s[i].rhs);

    for(i=0;i<n;i++){
        if(isconstant(s[i].rhs)){
            strcpy(value,s[i].rhs);

            for(j=i+1;j<n;j++){
                if(strcmp(s[j].rhs,s[i].lhs)==0){
                    strcpy(s[j].rhs,value);
                }
            }
        }
    }

    printf("\nAfter Constant Propagation\n");

    for(i=0;i<n;i++){
        printf("%s=%s\n",s[i].lhs,s[i].rhs);
    }

    return 0;
}
