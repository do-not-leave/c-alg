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
    char *str;
    *str = "hello world!";
    ungets(*str);
    return 0;
}
void ungets(char *s) {
 int len = strlen(s);
 void ungetch(int);
 while(len > 0){
 	ungetch(s[--len]);
 } 
}
