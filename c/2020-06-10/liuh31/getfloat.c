#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include "./getlib.h"

int getint(int *pn);
char getfloat(float *pn);

int main() 
{
    float *pn;

    getfloat(pn);
    printf("%f", *pn);
    return EXIT_SUCCESS;
}

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

char getfloat(float *pn)
{
    char c;
    int sign;
    float sum = 0.0;
    float i = 10;

    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        for (c = getch(); isdigit(c); c = getch()) {
            sum = 10 * sum + (c - '0');
            i *= 10;
        }
        *pn += sum * 10 / i;
    }
    
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}