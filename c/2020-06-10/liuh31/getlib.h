#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(char s[]) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    if (bufp + n >= BUFSIZE) {
        printf("ungets: too many characters\n");
    } else {
        for (int i = n; i >= 0; i--) {
            ungetch(s[i]);
        }
    }
}