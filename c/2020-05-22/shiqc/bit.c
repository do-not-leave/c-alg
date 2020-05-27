#include <stdio.h>
int main()
{
    char ch;
    printf("请输入一个字母：\n");
    ch = getchar();
    while (ch <'A' && ch >'z')
    {
        printf("输入有误，重新输入");
        ch = getchar();
    }

    if(ch & 32){
        ch = ch&223;
    }else{
        ch = ch|32;
    }
    putchar(ch);
    putchar('\n');
}
