#include<stdio.h>


#define LINE_MAX 100

void reverse(char line[]);

int main() {
    char c;
    char line[LINE_MAX];
    int len = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[len+1] = '\0';
            printf("原字符串:%s\n", line);
            reverse(line);
            len = 0;
        } else {
            line[len++] = c;
        }
    }

    return 0;
}

void reverse(char line[]) {
    int i = 0, j = 0;
    char t;
    while(line[++j] != '\0') {
    }
    printf("%d\n", j);
    
    printf("反转字符串:%s\n", line);
}
