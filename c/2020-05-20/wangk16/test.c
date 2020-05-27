#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int htoi(char s[])
{
    int i;
    int n;
    int resp;

    n = strlen(s);
    resp = 0;
    for ( i = 2; i< n ; i++)
    {
        if(s[i]>='0' && s[i]<='9'){
            resp = 16 * resp + (s[i]-'0');
        }else if(s[i]>='a' && s[i]<='f'){
            resp = 16 * resp + (s[i]-'a' + 10);
        }else if(s[i]>='A' && s[i]<='F'){
            resp = 16 * resp + (s[i]-'A' + 10);
        }
    }
        
    return resp;    
}

int main ()
{
   char str[10];
   int res;
   gets(str);
   if (str[0] != '0' || (str[1] != 'x' && str[1] != 'X')){
        printf("must 16 jin zhi\n");
        exit(1);
    }
   res = htoi(str);
   printf("res:%d",res);
}

