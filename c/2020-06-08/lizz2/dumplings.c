#include <stdio.h>
void reverse();
 
int main()
{
    printf("����һ���ַ���: ");
    reverse();
    return 0;
}
 
void reverse()
{
    char s;
    scanf("%c", &s);
 
    if( s != '\n')
    {
        reverse();
        printf("%c",s);
    }
}

