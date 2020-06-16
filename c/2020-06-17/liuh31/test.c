#include<stdio.h>
#include<stdlib.h>

void super_sort(int *a, int len);
void super_sort_1(int *a, int len);
void super_sort_2(int *a, int len);

int main()
{
    int a[10] = {10, 11, 0, 0, 2, 5, 7, 8, 3, 0};
    int len = 10;

    super_sort_2(a, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    return EXIT_SUCCESS;
}

void super_sort(int *a, int len)
{
    int t;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }

    int start = 0;
    if (a[0] == 0) {
        for (int i = 1; i < len; i++) {
            if (a[i] != 0) {
                a[start++] = a[i];
            }
        }
    }
    for (int i = start; i < len; i++) {
        a[i] = 0;
    }
    
}

void super_sort_1(int *a, int len)
{
    int t;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (a[j] == 0) {
                a[j] = 100;
            }
            if (a[j+1] == 0) {
                a[j+1] = 100;
            }
            if (a[j] > a[j+1]) {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (a[i] == 100) {
            a[i] = 0;
        } else {
            break;
        }
    }
}

void super_sort_2(int *a, int len)
{
    int t;
    int tail = len - 1;
    for (int i = 0; i <= tail; i++) {
        if (a[i] == 0) {
            int x = tail;
            for (x = tail; x >= 0; x--) {
                if (a[x] != 0) {
                    break;
                }
            }
            tail = x;
            t = a[i];
            a[i] = a[tail];
            a[tail--] = t;
        }
        if  (i <= tail) {
            for (int j = i; j > 0; j--) {
                if (a[j] < a[j-1]) {
                    t = a[j];
                    a[j] = a[j-1];
                    a[j-1] = t;
                }
            }
        }
        
    }
}