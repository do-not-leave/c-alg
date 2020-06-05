#include <stdio.h>

void doSort(int list[],int arrlen);

int main()
{
    int arr[10] = {73, 22, 74, 18, 46, 11, 84, 62, 10, 85};
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    doSort(arr,arrlen);
    for (int i = 0; i < arrlen; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void doSort(int list[],int arrlen)
{
    int temp;
    for (int i = 0; i < arrlen-1; i++)
    {
        for (int j = 0; j < arrlen - 1 - i; j++)
        {
            if (list[j] > list[j + 1])
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
