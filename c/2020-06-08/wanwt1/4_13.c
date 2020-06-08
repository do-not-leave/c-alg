#include <stdio.h>
#include <string.h>

void reverse(char s[],int i,int len)
{
    int c,j;

    j = len - (i + 1);
    
    if( i < j )
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        reverse(s,++i,len);
    }
}

int main()
{
    char s[] = "1234567";
    printf("%s\n",s);
    reverse(s,0,strlen(s));
    printf("%s\n",s);
}

