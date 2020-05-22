#include <stdio.h>
#include <string.h>
int main(void)
{
    /*字符数组赋初值*/
    char cArr[6] = {'I','L','O','V','E','C'};// char cArr[6] = {'I'，'L'，'O'，'V'，'E'，'C'};
    /*字符串赋初值*/
    char sArr[] = "ILOVEC";// ==  char sArr[] = {"ILOVEC"}  ==char sArr[7] = "ILOVEC";
    /*用sizeof（）求长度*/
    printf("cArr的长度=%d\n", sizeof(cArr));
    printf("sArr的长度=%d\n", sizeof(sArr));
    /*用strlen（）求长度*/
    printf("s cArr的长度=%d\n", strlen(cArr));
    printf("s sArr的长度=%d\n", strlen(sArr));
    /*用printf的%s打印内容*/
    printf("cArr的内容=%s\n", cArr);
    printf("sArr的内容=%s\n", sArr);
    return 0;
}

/*
    sizeof运算符指出的是整个数组的长度
    strlen返回的是存储在数组中的字符串的长度，而非数组本身长度
    strlen只计算可见字符，而不会包含结束字符‘\0’

    存储字符串到字符数组中要求数组长度至少为字符串长度strlen+1
    字符串以‘\0’为结束标志
*/