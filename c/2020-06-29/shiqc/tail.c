#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINS 10
#define LINES  100     
#define MAXLEN 100     //每一行最大字符数量

void error(char *);
int getline(char *, int);

int main(int argc, char *argv[])
{
    int ii;
	for (ii=0;ii<argc;ii++)
	{
		printf("arcv[%d] is %s\n", ii, argv[ii]);
	}

    char *p;                 //用于指示缓冲区中当前指针的位置 
    char *buf;               //用于指示分配出来的内存块开始处
    char *bufend;            //用于指示分配出来的内存块结尾处
    char line[MAXLEN];       //用于保存当前输入
    char *lineptr[LINES];    //定义一个字符指针数组，这样能节省很多空间
    int first, i, last, len, n, nlines;

    if (argc == 1)           //没有可选项，则使用默认配置
        n = DEFLINS;
    else if (argc == 2 && (*++argv)[0] == '-')  
        n = atof(argv[0] + 1);
    else
        error ("usgae: tail [-n]");

    if (n < 1 || n > LINES)   //容错处理
        n = LINES;

    for (i = 0; i < LINES; i++)   //字符指针数组初始化
        lineptr[i] = NULL;

    //分配一块内存，用于保存输入的文本行
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)   
        error ("tail: cannot allocate buf");

    bufend = buf + LINES * MAXLEN;   //指向内存末尾后一个字符
    last = 0;         //用于指示最新输入行所保存的位置
    nlines = 0;       //用于保存输入的文本行总数

    while ((len = getline(line, MAXLEN)) > 0)
    {
        //判断剩余空间是否充足，如果不充足则将p重新指向缓冲区的开头
        if (p + len + 1 >= bufend) 
            p = buf;

        // printf ("%s", line);
        lineptr[last] = p;       //保存当前缓冲区的地址
        strcpy (lineptr[last], line);   //字符串拷贝
        if (++last >= LINES)     //若大于限制的最大行数，则重置  
            last = 0;
        p += len + 1;            //p指到下一个未被使用的缓冲区地址处
        nlines++;
    }
    if (n > nlines)        
        n = nlines;
    first = last - n;   
    if (first < 0)    //轮回情况，即超过了最大行数，last重置了重新使用数组，所以小于0
        first += LINES;  //调整起始索引

    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf ("%s", lineptr[i]);

    return 0;
}

void error(char *s)
{
    printf ("%s\n", s);
    exit (1);
}

int getline(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
        
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
