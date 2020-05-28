#include<stdio.h>

void escape(char * s, char * t);

int main(){
    char t[20] = "H\\\nello";
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
            case '\n':
                printf("j0=%d\n",j);
                s[j++] = '\\';
                printf("j1=%d\n",j);
                s[j] = 'n';
                printf("j2=%d\n",j);
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