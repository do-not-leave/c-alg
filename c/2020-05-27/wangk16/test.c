#include<stdio.h>

void escape(char * s, char * t);

char main(){
    char t[20] = "\aHello,\nWorld!\b";
    char s[20];
    printf("in string:\n%s\n",t);
    escape(s,t);
    printf("out string:\n%s\n",s);
}

void escape(char * s,char * t)
{
    int i, j;
    i = j = 0;
    while (t[i])
    {
        switch (t[i])
        {
            case '\a':
                s[j] = '\\';
                s[j+1] = 'a';
                break;

            case '\b':
                s[j] = '\\';
                s[j+1] = 'b';
                break;
            case '\f':
                s[j] = '\\';
                s[j+1] = 'f';
                break;

            case '\n':
                s[j] = '\\';
                s[j+1] = 'n';
                break;

            case '\r':
                s[j] = '\\';
                s[j+1] = 'r';
                break;            

            case '\t':
                s[j] = '\\';
                s[j+1] = 't';
                break;

            case '\v':
                s[j] = '\\';
                s[j+1] = 'v';
                break;            
        
            default:
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];
}