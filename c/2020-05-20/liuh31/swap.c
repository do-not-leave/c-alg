#include<stdio.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *b ^ *a;
}

int main() {
    int a = 2;
    int b = 6;
    printf("a = %d; b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d; b = %d\n", a, b);
}

