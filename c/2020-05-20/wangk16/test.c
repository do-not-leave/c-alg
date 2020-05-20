#include <stdio.h>
#include <string.h>
#include <math.h>

int num(char t)
{
    int res;
    if(t=='a' || t=='A')
        res = 10;
    
    if(t=='b' || t=='B')
        res = 11;
    
    if(t=='c' || t=='C')
        res = 12;
    
    if(t=='d' || t=='D')
        res = 13;
    
    if(t=='e' || t=='E')
        res = 14;
    
    if(t=='f' || t=='F')
        res = 15;
    
    return res;
}

int atoi(char s[])
{
    int i;
    int n;
    double resp = 0;
    int tab;
    int number;

    n = strlen(s);
    // n = 0;
    for ( i = 0; i< n ; i++)
    {
        if(i=0 && s[i]!='0')
            resp = 0;
        if(i=1 && s[i]!='x' || s[i]!='X')
            resp = 0;
        if(i > 1){
            tab = n-(i+1);
            if(s[i]>'0' && s[i]<'9'){
                resp = resp + s[i] * pow(16,tab);
            }else{
                number = num(s[i]);
                resp = resp + number * pow(16,tab);
            }
        }

    }
        
    return resp;    
}

int main ()
{
   char str[] = "0x1f";
   int res;
   res = atoi(str);
   printf("res:%d",res);
}

