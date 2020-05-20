#include <stdio.h>
void reversewords();
 
int main()
{
    printf("输入一个字符串: ");
    reversewords();
 
    return 0;
}
 
void reversewords()
{
    char c;
    scanf("%c", &c);
 
    if( c != '\n')
    {
        reversewords();
        printf("%c",c);
    }
}
