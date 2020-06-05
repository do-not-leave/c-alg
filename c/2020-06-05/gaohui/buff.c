#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(char s[],int p)
{
	return (p > 0) ? s[--p] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int i;
	for(i = 0; s[i] != '\0'; i++)
	{
		ungetch(s[i]);
	}
}

int main()
{
	char *s = "hello world!";
	char *s2 = "A test for ungets!";
	int i;
	for(i = 0; s[i] != '\0'; i++)
	{
		ungetch(s[i]);
	}
	ungets(s2);

	printf("%s\n",buf);

	return 0;
}