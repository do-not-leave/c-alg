#include <stdio.h>
void reverse (char *s);

int main ()
{
    char *s;
    printf("输入字符串:");
    gets(s);
    reverse(s);
    return 0;
}

void reverse (char *s) {
    char r;
    if (*s == '\0') {
        return;
    } else {
        r = *s;
        s++;
        reverse(s);
        printf("%c",r);
    }
}
