#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
char *alloc(int);
// int getline(char *, int lim);

int get1line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c !='\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p; 
    char line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

