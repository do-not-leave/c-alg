#include<stdio.h>
#include<stdlib.h>
#define A_SIZE  10

void superSort(int arr[], int len);
int partition(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);

int main()
{
    int a[A_SIZE] = {0,13, 12, 0, 0, 1, 5, 7, 9, 3};

    superSort(a, A_SIZE);

    for (int i = 0; i < A_SIZE; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void superSort(int arr[], int len)
{
    int t;
    quickSort(arr,0,len-1);

    int start = 0;
    if (arr[0] == 0) {
        for (int i = 1; i < len; i++) {
            if (arr[i] != 0) {
                arr[start++] = arr[i];
            }
        }
    }
    for (int i = start; i < len; i++) {
        arr[i] = 0;
    }
    
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }

        if(i < j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[left] = arr[i];
    arr[i] = pivot;
    return i;
}