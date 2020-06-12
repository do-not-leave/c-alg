#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getfloat(float *pn);
int getch(void);
void ungetch(int);

int main(void)
{
	float number = 0.0;

	printf("请输入待转换为数字的字符串\n");
	
	getfloat(&number);
	printf("字符串转换为数字为：%.2f\n", number);
	return 0;
}

int getfloat(float *pn)
{
	int c, sign;
	float power = 1.0;
	int mask = 0;

	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if(c == '+' || c == '-')
	{
		mask = 1;
		c = getch();
	}

	if(!isdigit(c) && c != '.')
	{
		ungetch(c);
		if(mask)
			ungetch((sign == -1) ? '-' : '+');
		return 0;
	}


	for(*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (float)(c - '0');

	if(c == '.')
	{
		for(c = getch(); isdigit(c); c = getch())
		{
			*pn = 10.0 * *pn + (float)(c - '0');
			power *= 10.0;
		}
	}
	*pn = (*pn / power) * (float)sign;
	if(c != EOF)
		ungetch(c);
	return c;
}

int getch(void)
{
	return (bufp == 0) ? getchar() : buf[--bufp];
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
