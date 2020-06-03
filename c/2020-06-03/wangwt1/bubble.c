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

    for (i=0; i<10; i++) {
        for (j=0; j<9; j++) {
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
}