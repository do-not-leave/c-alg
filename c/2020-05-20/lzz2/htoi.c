1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

int htoi(char s[])
{
    int len = strlen(s);
    int sum = 0;
    int i;
    for (i = 2; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'F')
        {
            s[i] = s[i] - 'A' + 10 + '0';
        }
        sum += (s[i] - '0') * (pow(16.0, len - 1 - i));
    }
    return sum;
}


int main()
{
    char s[10];
    scanf("%s", s);
    printf("%d\n", htoi(s));
}