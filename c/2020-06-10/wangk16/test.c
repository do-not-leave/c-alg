#include <stdio.h>
#include <ctype.h>
 
#define BUFFERMAX 100
#define MAXLEN 18
 
int bufferIndex = 0;
int buffer[BUFFERMAX];
 
int getch();
void ungetch(int);
int getfloat(double *p);
 
int main() {
 
    double array[MAXLEN] = {0.0};
    for (int i = 0; i < MAXLEN && getfloat(&array[i]) != EOF; ++ i) 
        printf("%.2f,", array[i]);
 
 
    return 0;
}
 
int getch() {
    return (bufferIndex > 0) ? buffer[--bufferIndex] : getchar();
}
 
void ungetch(int c) {
    if (bufferIndex < BUFFERMAX)
        buffer[bufferIndex ++] = c;
}
 
int getfloat(double *p) {
    int c, sign;
    sign = 1;
    *p = 0.0;
 
    while (isspace(c = getch()))
        ;
 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        c = getch();
        while (!isspace(c) && c != EOF) {
            c = getch();
        }
    }
 
    if (c == '+' || c == '-') {
        sign = (c == '-') ? -1 : 1;
        c = getch();
    }
 
    if (!isdigit(c) && c != '.') {
        while (!isspace(c) && c != EOF) {
            c = getch();
        }
    }
 
    while (isdigit(c)) {
        *p = 10 * *p + c -'0';
        c = getch();
    }
 
    if (c == '.') {
        int ten = 1;
        double result = 0;
        while (isdigit(c = getch())) {
            result = 10 * result + c - '0';
            ten *= 10;
        }
 
        result /= ten;
        *p += result;
    }
    if (*p != 0.00)
        *p *= sign;
 
    while (!isspace(c) && !isdigit(c) && c != EOF) {
        c = getch();
    } 
 
    if (isdigit(c)) {
        c = getch();
        while (!isspace(c) && c != EOF) {
            c = getch();
        }
    }
 
    if (c != EOF)
        ungetch(c);
 
    return c;
}