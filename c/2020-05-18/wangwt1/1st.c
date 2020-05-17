#include <stdio.h>

void rev(int *str, int l) {
    int tmp, i;
    for (i = 0; i < l / 2; i++) {
        tmp = str[l-i-1];
        str[l-i-1] = str[i];                 
        str[i] = tmp;
    }
}

int main()
{
    int str[100];
    int c, i;
    int l = 0;
    int tmp;
    while ((c = getchar()) != EOF)
    {
        str[l] = c;
        if (c == '\n') {
            rev(str, l);
            for (i = 0; i < l; i++) {
                printf("%c", str[i]);
                str[i] = 0;
            }
            l = 0;
            printf("\n");
        }
        l++;
        if (l > 100) {
            return 0;
        }
    }
    
}