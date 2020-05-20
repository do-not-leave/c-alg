#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>

int change(char a[])
{
    int len = strlen(a);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'F')
        {
            a[i] = a[i] - 'A' + 10 + '0';
        }
        sum += (a[i] - '0') * (pow(16.0, len - 1 - i));
    }
    return sum;
}


int main()
{
    char a[10];
    scanf("%s", a);
    printf("%d\n", change(a));
}