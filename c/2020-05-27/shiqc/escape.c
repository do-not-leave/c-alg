#include<stdio.h>

void escape(char s[],char t[]);
void descape(char s[],char t[]);

int main(){
    char s[50]="";
    char t[50]="Hello\tworld\n";
    char u[50]="";
    int i=0;
    escape(s,t);
    while(s[i]){
        printf("%c",s[i++]);
    }
    printf("\n");
    descape(u,s);
    i=0;
    while(u[i]){
        printf("%c",u[i++]);
    }
    return 0;
}

void escape(char s[],char t[]){

    int i=0,j=0;
    while(t[i]){
        switch(t[i]){
            case '\n':
                s[j++]='\\';
                s[j++]='n';
                break;
            case '\t':
                s[j++]='\\';
                s[j++]='t';
                break;
            default:
                s[j++] = t[i];  
        }
        ++i;
    }
    s[j]='\0';
}

void descape(char s[],char t[]){

    int i=0,j=0;
    while(t[i]){
        switch(t[i]){
            case '\\':
                switch(t[i+1]){
                    case 't':
                        s[j++]='\t';
                        i++;
                        break;
                    case 'n':
                        s[j++]='\n';
                        i++;
                        break;
                    default:
                        s[j++]='\\';
                }
                break;
            default:
                s[j++]=t[i];
        }
        ++i;
    }
    s[j]='\0';
}