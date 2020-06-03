#include <stdio.h>
#include <stdlib.h>

void sort(int list[], int len);

int main () {
    int len = 4;
    int list[4] = {5, 9, 2, 1};
    sort(list, len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", list[i]);
    }
    return EXIT_SUCCESS; 
}

void sort(int list[], int len) {
    int t = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len - i; j++) {
            if (list[j] < list[j-1]) {
                t = list[j];
                list[j] = list[j-1];
                list[j-1] = t;
            }
        }
    }
}