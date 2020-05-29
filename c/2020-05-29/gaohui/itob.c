#include<stdio.h>
#define MAX 50
 
void itob(int n,char s[],int b)
{
    int i,j,sign;
    void reverse(char s[]);
     
    if((sign=n)<0)
        n=-n;
    i=0;
    do{
        j=n%b;
        s[i++] = (j<=9) ? j+'0' : j+'a'-10;
    }while((n/=b)>0);
    if(sign<0)
        s[i++]='-';
    s[i]='\0';
    reverse(s);
}

void reverse(char s[])//将s字符顺序颠倒的函数
{
    int i,j;
    char temp;
    i=0;
    while(s[i]!='\0')
      ++i;
    --i;//从'\0'倒退一个位置，保证颠倒后得到的字符串的第一个不会是字符串结束符
    if(s[i]=='\n')//从'\0'倒退，若是回车，继续倒退
      --i;
    j=0;
    while(j<i){
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;
        --i;
        ++j;
    }
}


int main(void)
{
    int n,b;
    char s[MAX];
    n=31;
    b=16;
    itob(n,s,b);
    printf("%s",s);
    return 0;
}