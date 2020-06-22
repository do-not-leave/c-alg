#include <stdio.h>

void showArr(int *a, int l, char s[])
{
    printf("%s", s);
    for (int i=0; i<l; i++) {
        printf("%3d", *a);
        a++;
    }

    printf("\n");
}

int main()
{
    int len = 8;
    int arr[8] = {4, 2, 20, 43, 7, 9, 31, 6};
    int tmp, j;
    int *pArr = arr;

    showArr(pArr, len, "before sort:");
    for (int i = 1; i < len; i++) {
        tmp = arr[i];
        for (j = i-1; j >= 0 && tmp < arr[j]; j--)
            arr[j+1] = arr[j];

        arr[j+1] = tmp;
    }
    showArr(pArr, len, "after  sort:");
}

