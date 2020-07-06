#include <stdio.h>
#include <string.h>
#define NUMERIC   1    //字符串排序
#define DECR      2     
#define LINES     100   //定义最大长度
#define MAXLEN 1000  
#define ALLOCSIZE 1000
int numcmp(char *,char *); 
int readlines(char *lineptr[],int maxlines); //读取文件最大行重置 lineptr数组
void myqsort(void *v[],int left,int right,int (*comp)(void *,void *)); //快速排序
void writelines(char *lineptr[],int nlines,int decr); //写文件

static char option = 0;
int main(int argc,char *argv[])
{

    //初始化行数
    char *lineptr[LINES];
    int nlines;     
    int c,rc=0;    

    while(--argc > 0 && (*++argv)[0] == '-')
        while( c == *++argv[0])
            switch(c)
            {
                case 'n':  //整数排序
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort:illegal option %c\n",c);
                    argc = 1;
                    rc = -1;
                    break;
            }
    if (argc)
        printf("Usage: sort -nr \n");
    else
        if((nlines = readlines(lineptr,LINES)) > 0)
        {
            if(option & NUMERIC)
                myqsort((void **)lineptr,0,nlines -1,(int (*)(void *,void *))numcmp);
            else
                myqsort((void **)lineptr,0,nlines -1,(int (*)(void *,void *))numcmp);
            writelines(lineptr,nlines,option & DECR);
        }
        else
        {
            printf("input too big to sort \n");
            rc = -1;
        }
        return rc;
}

//写文件，之前的章节里有
void writelines(char *lineptr[],int nlines,int decr)
{
    int i;
    if(decr)
    for(i=nlines-1;i>=0;i--)
        printf("%s\n",lineptr[i]);
    else
        for(i=0;i<nlines;i++)
        printf("%s\n",lineptr[i]);
}

#include<stdlib.h>

int numcmp(char *s1,char *s2)
{
    double v1,v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if( v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int mgetline(char *,int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines = 0;
    while((len = mgetline(line,MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
        }
    return nlines;
}



static char allocbuf[ALLOCSIZE];   
static char *allocp=allocbuf;      

char *alloc(int n) 
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp -n;
    }
    else
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


void myqsort(void *v[],int left,int right,int (*comp)(void *,void *))
{
    int i,last;
    void swap(void *v[],int,int);

    if(left >= right)
        return;

    swap(v,left,(left+right)/2);

    last = left;

    for(i=left+1;i<=right;i++)
        if((*comp)(v[i],v[left])<0)
            swap(v,++last,i);
    swap(v,left,last);

    myqsort(v,left,last-1,comp);
    myqsort(v,last+1,right,comp);
}

void swap(void *v[],int i,int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int mgetline(char s[],int lim)
{
    int c,i;

    for(i=0;i<lim-1 && (c=getchar())!= EOF && c!='\n';++i)
        s[i] = c;
    if( c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
