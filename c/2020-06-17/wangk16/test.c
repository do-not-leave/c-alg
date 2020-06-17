#include<stdio.h>

void strcopy(char *s, char *t)
{
    int i;
    i = 0;
    for ( i = 0; t[i] != '\0'; i++)
    {
        s[i] = t[i];
    }
    s[i] = '\0';
}

void strcpy1(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

int main()
{
    char t[6] = "hello";
    char s[10];
    strcopy(s,t);
    //strcpy1(s,t);
    printf("%s",s);
}