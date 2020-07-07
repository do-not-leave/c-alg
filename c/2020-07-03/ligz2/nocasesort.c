#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A_LEN 8

int nocasecmp(const char *v1, const char *v2);
int main(int argc, char *argv[]) {
    int nocase = 0;

    if (argc > 1 && strcmp(argv[1], "-f") == 0) {
        nocase = 1;
    }
    char arr[A_LEN] = {'m','a','f','d','F','A','p','a'};

    qsort(arr, A_LEN, sizeof(char), (int (* _Nonnull)(const void *, const void *))(nocase ? nocasecmp : strcmp));

    for (int i = 0; i < A_LEN; i++) {
        printf("%c ", arr[i]);
    }
    return EXIT_SUCCESS;
}

int numcmp(int *v1, int *v2) {
    int reverse = 0;
    if (*v1 < *v2) {
        return reverse ? 1 : -1;
    } else if (*v1 > *v2) {
        return reverse ? -1 : 1;
    } else {
        return 0;
    }
}

int nocasecmp(const char *v1, const char *v2) {
    return strncasecmp(v1, v2, sizeof(char));
}
