#include<stdio.h>
#include<stdlib.h>

void reverse(char s[], int i);

int main() {
    char *s = NULL;
    size_t mem;
    ssize_t len;

    printf("input: ");

    len = getline(&s, &mem, stdin);

    reverse(s, 0);

    return EXIT_SUCCESS;
}

void reverse(char s[], int i) {
    if (s[i] != '\0') {
        int j = i + 1;
        reverse(s, j);
        putchar(s[i]);
    }
}