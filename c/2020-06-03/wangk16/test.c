#include<stdio.h>
#include<stdlib.h>

void buble_sort(int arr[], int length)
{
    int i, j, max;
    for(i=0;i<length-1;i++)
    {
        for(j=0;j<length-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                max = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = max; 
            }
        }
    }
}

int  main()
{
    int arr_num[] = {73,22,74,18,46,11,84,62,10,85};
    buble_sort(arr_num, 10); 
    for(int i=0; i<10; i++)
        printf("%d  ", arr_num[i]);
    printf("\n");
    system("pause");
    return 0;
}