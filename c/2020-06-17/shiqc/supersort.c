#include<stdio.h>

void SuperSort1(int* A,int nSize)
{

    int *p_zero = A; //指向最开始的零值
    int zero_num = 0;
    int end = nSize -1;
    // 先找出0值移动到后面并记录个数
    for(int s=0; s<end; s++){
        if(A[s] == 0){
            zero_num++ ;
            for (; end > s; end--)
            {
                if(A[end] !=0){
                    A[s] = A[end];
                    A[end] = 0;
                    break;
                }
            }
        }
    }
 
    int tmp;
    for(int i=0; i< nSize-1 -zero_num; i++){
        for (int j = 0; j < nSize -zero_num -2 -i; j++)
        {
            if(A[j]>A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}

int main()
{

    int a[10] = {10, 11, 0, 0, 2, 5, 7, 8, 3, 0};
    int len = 10;
    SuperSort1(a,len);
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}