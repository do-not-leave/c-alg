#include <stdio.h>
#define STRING_SIZE 100
void str_cpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0') {
        ;
    }
}
int main ()
{
    //需要声明字符数组的长度，否则直接声明一个指针，下文操作指针时会有指针越界have a try:  char *t
    char t[STRING_SIZE];
    char *f = "aguihellohhh";
    str_cpy(t,f);
    printf("%s\n",t);
}

