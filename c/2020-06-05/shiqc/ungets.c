#include <stdio.h>
#include <string.h>

#define MAXSIZE  20


char buf[MAXSIZE];
int bufp = 0;

void ungets(char s[]);
void ungetch(int c);


int main(){
    char string[MAXSIZE] = "hello meimei";
    ungets(string);
    printf("%s\n",buf);
    return 0;
}

void ungets(char s[]){
    int length = strlen(s);
    while (length > 0)
    {
        ungetch(s[--length]);
    }
    
}

void ungetch(int c){
    if (bufp >= MAXSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
