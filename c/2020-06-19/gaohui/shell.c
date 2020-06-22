#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#ifndef N
#define N 100
#endif // N

int arr[N];
 
void Shell_Sort(int *arr)
{
    int i, j, k, tmp;
    int incre;  
 
    for(incre = N/20; incre > 0;incre /= 2)
    { 
        for(i = incre; i < N/10; i++)
        {
            tmp = arr[i];
           // 很明显和插排的不同就是插排这里是j = i - 1
            j = i - incre;
            while( j >= 0 && tmp < arr[j])
            {
                arr[j + incre] = arr[j];
                j -= incre;
            }
            arr[j + incre] = tmp;
 
        }
    }
}
 
int main()
{
    int i;
 
 
    printf("please enter 10 numbers: \n");
 
    for(i = 0;i < N/10;i++)
    {
        scanf("%d", &arr[i]);
    }
 
    Shell_Sort(arr);
 
    printf("\n");
    printf("the ordered array is: \n");
 
    for(i = 0;i < N/10;i++)
    {
        printf("%4d", arr[i]);
 
    }
}
