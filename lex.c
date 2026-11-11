
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int iskeyword(char str[]){
    char keywords[][10]={
        "int","float","char","if","else","void"
    };

    int n=sizeof(keywords)/sizeof(keywords[0]);

    for(int i=0;i<n;i++){
        if(strcmp(str,keywords[i])==0)
            return 1;
    }
    return 0;
}

int main(){
    FILE *fp;
    char ch,buffer[20];
    int i=0;

    fp=fopen("input.txt","r");

    if(fp==NULL){
        printf("FILE NOT FOUND");
        return 0;
    }

    while((ch=fgetc(fp))!=EOF){

        if(ch=='/'){
            char next=fgetc(fp);

            if(next=='/'){
                while((ch=fgetc(fp))!=EOF && ch!='\n');
                continue;
            }
            else if(next=='*'){
                char prev=' ';
                while((ch=fgetc(fp))!=EOF){
                    if(prev=='*' && ch=='/')
                        break;
                    prev=ch;
                }
                continue;
            }
            else{
                printf("/ --> Operator\n");
                if(next!=EOF)
                    fseek(fp,-1,SEEK_CUR);
                continue;
            }
        }

        if(isalpha(ch) || ch=='_'){
            buffer[i++]=ch;

            while((ch=fgetc(fp))!=EOF &&
                  (isalnum(ch) || ch=='_')){
                if(i<19)
                    buffer[i++]=ch;
            }

            buffer[i]='\0';
            i=0;

            if(iskeyword(buffer))
                printf("%s --> Keyword\n",buffer);
            else
                printf("%s --> Identifier\n",buffer);

            if(ch!=EOF)
                fseek(fp,-1,SEEK_CUR);
        }

        else if(isdigit(ch)){
            while((ch=fgetc(fp))!=EOF && isdigit(ch));
            printf("Number --> Constant\n");

            if(ch!=EOF)
                fseek(fp,-1,SEEK_CUR);
        }

        else if(ch=='+'||ch=='-'||ch=='*'||
                ch=='/'||ch=='='||ch=='<'||
                ch=='>'||ch=='%'){
            printf("%c --> Operator\n",ch);
        }

        else if(ch=='('||ch==')'||ch=='{'||
                ch=='}'||ch==';'||ch==','){
            printf("%c --> Special Symbol\n",ch);
        }
    }

    fclose(fp);
    return 0;
}
