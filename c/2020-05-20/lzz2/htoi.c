#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>


int atoi(char s[]);

int atoi(char s[])
{
    int i,n;
    n = 0; 
    for (i = 0; s[i] >= "0" && s[i] <= '9'; ++i)
    {
      n = 10*n + (s[i] - '0');
    }
    return n;
}

int main()
{
	char s[100];
	scanf(s,'123123');
	printf(s);
    printf(atoi(s));
}
