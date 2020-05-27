#include <stdio.h>
#include <string.h>

void escape(char* dst, char* src) {
    while (*src != '\0')
    {
        switch (*src)
        {
        case '\t':
            *dst++ = '\\';
            *dst++ = 't';
            src++;
            break;
        case '\n':
            *dst++ = '\\';
            *dst++ = 'n';
            src++;
            break;
        default:
            *dst++ = *src++;
            break;
        }
    }

    *dst++ = '\0';
}

void unescape(char* dst, char* src)
{
    while (*dst != '\0')
    {
        switch (*dst)
        {
        case '\\':
            if (*(dst+1) == 't') {
                *src++ = '\t';
                dst+=2;
                break;
            } else if(*(dst+1) == 'n') {
                 *src++ = '\n';
                dst+=2;
                break;
            } else {
                *src++ = *dst++;
            }
            break;
        default:
            *src++ = *dst++;
            break;
        }
    }

    *src = '\0';
}

int main()
{
    char s1[100] = "abc";
    char s2[100] = "\\\t1\n1";
    printf("s1:%s,s2:%s\n", s1, s2);
    escape(s1, s2);

    printf("escape结果：%s\n", s1);


    unescape(s1, s2);
    printf("unescape结果：%s\n", s2);

    return 0;
}