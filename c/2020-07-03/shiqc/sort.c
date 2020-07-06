#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLEN 1000
#define ALLOCSIZE 10000

char allocbuf[ALLOCSIZE];
char *lineptr[MAXLINES];
char *allocp = allocbuf;

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int getlines(char s[], int lim);
void iqsort(void *lineptr[], int left, int right, int (*comp)(const void *, const void *), int sort_order);
int numcmp(const char *s, const char *t);
int charcmp(const char *s, const char *t);//不区分大小写排序
int listcmp(const char *s, const char *t);//按照目录顺序排序
int list_charcmp(const char *s, const char *t);//按照目录顺序，不区分大小写排序
void swap(void *v[], int i, int j);
char *alloc(int n);
void afree(char *p);

int main(int argc, char *argv[])
{
	int nlines;
	int sort_mode = 0;//排序模式
	int sort_order = -1;//排序顺序

	if(argc == 1)
	{
		sort_mode = 0;//字符排序
		sort_order = -1;//顺序排序
	}
	else if(argc == 2)
	{
		if(!strcmp(argv[1], "-n"))
			sort_mode = 1;//数值排序
		else if(!strcmp(argv[1], "-r"))
		{
			sort_mode = 0;
			sort_order = 1;//逆序排序
		}
		else if(!strcmp(argv[1], "-f"))
		{
			sort_mode = 2;//不区分大小写排序
		}
		else if(!strcmp(argv[1], "-d"))
		{
			sort_mode = 3;//按照目录顺序排序
		}
		else
		{
			printf("parameter error!\n");
			return -1;
		}

	}
    else
	{
		printf("parameter error!\n");
		return -1;
	}



	if((nlines = readlines(lineptr, MAXLINES)) > 0)
	{
		iqsort((void **) lineptr, 0, nlines - 1, (int (*)(const void *, const void *)) 
			((!sort_mode) ? strcmp : ((sort_mode == 1) ? numcmp : ((sort_mode == 2) ? charcmp : 
			((sort_mode == 3) ? listcmp : list_charcmp)))), sort_order);
		writelines(lineptr, nlines);
	}
	else
	{
		printf("input is empty!\n");
		return -1;
	}

	afree(allocbuf);
	return 0;
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getlines(line, MAXLEN)) > 0)
	{
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

char *alloc(int n)
{
	if(allocp + n <= allocbuf + ALLOCSIZE)
	{
		allocp += n;
		return allocp - n;
	}
	else
		return NULL;
}

int getlines(char s[], int lim)
{
	int c, i;

	for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if(c == '\n')
		s[i++] = '\n';

	s[i] = '\0';
	return i;

}

void iqsort(void *v[], int left, int right, int (*comp)(const void *, const void *), int sort_order)
{
	int i, last;

	void swap(void *v[], int, int);

	if(left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;

	for(i = left + 1; i <= right; i++)
		if((*comp) (v[i], v[left]) == sort_order)
			swap(v, ++last, i);
	
	swap(v, left, last);
	iqsort(v, left, last - 1, comp, sort_order);
	iqsort(v, last + 1, right, comp, sort_order);
}

int numcmp(const char *s, const char *t)
{
	double v1, v2;
	v1 = atof(s);
	v2 = atof(t);

	if(v1 < v2)
		return -1;
	else if(v1 > v2)
		return 1;
	else
		return 0;
}

int charcmp(const char *s, const char *t)
{
	for(; *s && *t && tolower(*s) == tolower(*t); s++, t++)
		;
	if(tolower(*s) < tolower(*t))
		return -1;
	else if(tolower(*s) > tolower(*t))
		return 1;
	else
		return 0;
}

int listcmp(const char *s, const char *t)
{
	int c1, c2;
	do
	{
		while(!isalnum(*s) && *s != ' ' && *s != '\0')
			s++;
		while(!isalnum(*t) && *t != ' ' && *t != '\0')
			t++;
		if(*s == '\0' && *t == '\0')
			return 0;
		c1 = *s;
		s++;
		c2 = *t;
		t++;
	}while(c1 == c2);

	if(c1 < c2)
		return -1;
	else
		return 1;
}

int list_charcmp(const char *s, const char *t)
{
	int c1, c2;
	do
	{
		while(!isalnum(*s) && *s != ' ' && *s != '\0')
			s++;
		while(!isalnum(*t) && *t != ' ' && *t != '\0')
			t++;
		if(*s == '\0' && *t == '\0')
			return 0;
		c1 = tolower(*s);
		s++;
		c2 = tolower(*t);
		t++;
	}while(c1 == c2);

	if(c1 < c2)
		return -1;
	else
		return 1;

}

void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void writelines(char *lineptr[], int nlines)
{
	for(int i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

void afree(char *p)
{
	if(allocbuf <= p && p >= allocbuf + ALLOCSIZE)
		allocp = p;
}
