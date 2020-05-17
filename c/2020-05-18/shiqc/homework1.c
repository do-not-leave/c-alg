#include <stdio.h>
#define MAXLINE 1000 
int getline(char line[], int maxline);
void Reverse(char str[], int);
void main()
{
    int len;           
    char line[MAXLINE];    
    while ((len = getline(line, MAXLINE)) > 0){
        printf("输入字符串: %s\n", line);
        Reverse(line,len);
        printf("反转后的: %s\n", line);
    }
    
}

int getline(char s[], int lim)
{
    int c, i;
    printf("请输入 ");
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)   
        if (c == '\n'){
            s[i] = '\0';
            break;
        }else{
            s[i] = c;
        }
    return i;
}

void Reverse(char s[],int n){ 
    for(int i=0,j=n-1;i<j;i++,j--){ 
        char c=s[i]; 
        s[i]=s[j]; 
        s[j]=c; 
    } 
} 
