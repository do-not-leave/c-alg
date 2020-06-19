#include<stdio.h>

int Arr[10] = {3, 1, 11, 5, 8, 2, 0, 9, 13, 81};

void insertSort(int *A,int len);

void insertSort(int *A,int len)
{
    int tmp,j,i;
    for(i = 1; i< len;i++){
        if(A[i] < A[i - 1]){
            tmp = A[i];
            j = i - 1;
            while (A[j] > tmp)
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = tmp;
        }
    }
}

int main()
{
    int i;

    for(i = 0; i < 10; i++)
        printf("%d ", Arr[i]);
    printf("\n");

    insertSort(Arr,10);

    for(i = 0; i < 10; i++)
        printf("%d ", Arr[i]);
    printf("\n");

    return 0;
}

