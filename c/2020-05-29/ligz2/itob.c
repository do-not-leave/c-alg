#include <stdio.h>
#include <string.h>

/**
 * 整数n转换成b进制的字符串s，b只能为2~10，16
*/
void itob (int n, char *s, int b);
void itoblt10 (int n, char *s, int b);
void itobe16 (int n, char *s);
void reverse(char *s);

int main ()
{
    int in;
    char *s;
    scanf("%d", &in);
    itoblt10(in, s, 2);
    printf("input:%d    to2c:%s\n", in, s);
    itoblt10(in, s, 8);
    printf("input:%d    to8c:%s\n", in, s);
    itoblt10(in, s, 10);
    printf("input:%d    to10c:%s\n", in, s);
    itobe16(in, s);
    printf("input:%d    to16c:%s\n", in, s);
    return 0;
}

void itoblt10(int n, char *s, int b) {
    if (b >10 || b<0) {
        printf("进制错误，必须大于0，不大于10");
    }
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % b + '0';
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char *s)
{       
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itobe16(int n, char *s) {

    int i, sign, t;
    char c;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        t = n % 16;
        if (t > 9) {
            c = (t - 10) + 'A';
        } else {
            c = t + '0';
        }
        s[i++] = c;
    } while ((n /= 16) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
