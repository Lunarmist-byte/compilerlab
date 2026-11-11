
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[100],postfix[200];
int top=-1,p=0,temp=1;

int priority(char c){
    if(c=='*'||c=='/')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    return 0;
}

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int main(){
    char exp[100],token[20],op1[20],op2[20],t[20];
    char operands[100][20];
    int i=0,k;

    printf("Enter the expression: ");
    scanf("%99s",exp);

    while(exp[i]!='\0'){
        if(isalnum((unsigned char)exp[i])){
            k=0;
            while(isalnum((unsigned char)exp[i]))
                token[k++]=exp[i++];
            token[k]='\0';
            strcpy(postfix+p,token);
            p+=k;
            postfix[p++]=' ';
        }
        else if(exp[i]=='(')
            push(exp[i++]);
        else if(exp[i]==')'){
            while(top>=0&&stack[top]!='(')
                postfix[p++]=pop();
            if(top>=0)
                pop();
            i++;
        }
        else if(strchr("+-*/",exp[i])){
            while(top>=0&&stack[top]!='('&&
                  priority(stack[top])>=priority(exp[i]))
                postfix[p++]=pop();
            push(exp[i++]);
        }
        else{
            i++;
        }
    }

    while(top>=0)
        postfix[p++]=pop();

    postfix[p]='\0';
    top=-1;
    i=0;

    while(postfix[i]!='\0'){
        if(postfix[i]==' '){
            i++;
            continue;
        }

        if(isalnum((unsigned char)postfix[i])){
            k=0;
            while(postfix[i]!=' '&&postfix[i]!='\0')
                token[k++]=postfix[i++];
            token[k]='\0';
            strcpy(operands[++top],token);
        }
        else{
            char op=postfix[i++];
            strcpy(op2,operands[top--]);
            strcpy(op1,operands[top--]);
            sprintf(t,"t%d",temp++);
            printf("%s=%s%c%s\n",t,op1,op,op2);
            strcpy(operands[++top],t);
        }
    }

    return 0;
}
