#include<stdio.h>
#include<stdlib.h>


#define LINE_MAX 100

int getLine(char line[], int maxLine);
void reverse(char line[]);

int main() {
    char line[LINE_MAX];

    while (getLine(line, LINE_MAX) != 0) {
        printf("origin string: %s\n", line);
        reverse(line);
        printf("reverse string: %s\n\n", line);
    }

    return EXIT_SUCCESS;
}

int getLine(char line[], int maxLen) {
    char c;
    int strLen = 0;
    printf("input: ");
    while ((c = getchar()) != EOF) {
        if (c == '\n'){
            line[strLen] = '\0';
            break;
        } else if (strLen >= (maxLen - 1)){
            continue;
        }else {
            line[strLen++] = c;
        }
    }
    return strLen;
}

void reverse(char line[]) {
    int i = 0, j = 0;
    char t;
    while(line[j+1] != '\0') {
        j++;
    }
    while(i < j) {
        t = line[i];
        line[i] = line[j];
        line[j] = t;
        i++;
        j--;
    }
<<<<<<< HEAD
    printf("%d\n", j);
    
    printf("反转字符串:%s\n", line);
}
=======
}
>>>>>>> 31ea19bd79c5140a8402710615081a7c8a2aa6ec
