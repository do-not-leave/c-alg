#include<stdio.h>
#include<string.h>

#define BUFSIZE 100 

char buf[BUFSIZ];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZ){
        printf("characters too long\n");
    }else{
        buf[bufp++] = c;
    }
}

void ungets(const char *s)
{
    int i = strlen(s);
    while (i > 0){
        ungetch(s[--i]);
    }

}

int main (void)
{
    char *s = "hello,this is test.";
    int c;

    ungets(s);
    while ((c = getch()) != EOF){
        putchar(c);
    }
    return 0;
}