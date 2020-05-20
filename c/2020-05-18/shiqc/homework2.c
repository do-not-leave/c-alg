#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 
int getline(char line[], int maxline);
void Reverse(char str[], int);
int htoi(char s[]);

int main()
{
   int len;           
    char line[MAXLINE];    
    while ((len = getline(line, MAXLINE)) > 0){
        printf("%d\n", htoi(line));
    }
    
    return 0;
}


int htoi(char s[])
{
    int start = 0, end;
    int inte = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        start = 2;
    }
    int j = 0;
    while (s[j++] != '\0')
    {
    }
    end = j - 2;
    printf("end : %d \n", end);
    for (int i = 1; end >= start; i = i * 16)
    {
        if (s[end] >= '0' && s[end] <= '9')
        {
            inte = inte + (s[end] - '0') * i;
        }
        else if (s[end] >= 'a' && s[end] <= 'f')
        {
            inte = inte + (s[end] - 'a' + 10) * i;
        }
        else if (s[end] >= 'A' && s[end] <= 'F')
        {
            inte = inte + (s[end] - 'A' + 10) * i;
        }
        end--;
    }
    return inte;
}

int getline(char s[], int lim)
{
    int c, i;
    printf("输入16进制数 ");
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i)   
        if (c == '\n'){
            s[i] = '\0';
            break;
        }else{
            s[i] = c;
        }
    return i;
}