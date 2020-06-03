#include <stdio.h>

int main()
{
    int arr[] = {73,22,74,18,46,11,84,62,10,85};
    int i,j,tmp;
    printf("排序前: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int cnt = 0;
    for (i=0; i<10; i++) {
        for (j=0; j<i; j++) {
            cnt++;
            if (arr[j] > arr[j+1]) {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    printf("排序后: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("循环次数%d\n", cnt);
}