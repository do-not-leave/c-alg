#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numcmp(int *, int *);
int numcmpr(int *, int *);

int main(int argc, char *argv[]) {

    int nlines;
    int reverse = 0;

    if (argc > 1 && strcmp(argv[1], "-r") == 0) {
        reverse = 1;
    }

    int arr[] = {2, 4, 7, 20, 8, 3, 5};

    qsort(arr, 7, sizeof(int), (int (* _Nonnull)(const void *, const void *))( reverse ? numcmpr : numcmp));

    for (int i = 0; i < 7; i++) {
        printf("%d, ", arr[i]);
    }
    return EXIT_SUCCESS;
}

int numcmp(int *v1, int *v2) {
    if (*v1 < *v2) {
        return -1;
    } else if (*v1 > *v2) {
        return 1;
    } else {
        return 0;
    }
}

int numcmpr(int *v1, int *v2) {
    if (*v2 < *v1) {
        return -1;
    } else if (*v2 > *v1) {
        return 1;
    } else {
        return 0;
    }
}

