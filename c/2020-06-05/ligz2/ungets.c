#include <stdio.h>
#include <string.h>
#define BUF_SIZE 100
char buf[BUF_SIZE];
int bufp = 0;

void ungets(char *s);
int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
int main()
{
    char *str, ch;

    printf("请输入一个字符串：");
    gets(str);
    printf("您输入的字符串是：%s", str);
    ungets(str);
    printf("栈字符串是：%s", buf);
    while ((ch = getch()) != EOF) {
        printf("当前读取的输入字符：%c\n", ch);
    }

    return(0);
}
void ungets(char *s) {
    while (*s !='\0') {
        if (bufp >=BUF_SIZE) {
            printf("字符串超长");
            break;
        }
        buf[bufp++] = *s;
        s++;
    }
}


