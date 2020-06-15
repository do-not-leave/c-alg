#include<stdio.h>

int Arr[10] = {3, 1, 11, 5, 8, 2, 0, 9, 13, 81};

void quickSort(int left,int right);

void quickSort(int left,int right)
{
    int l,r,t,key;    
    if(left > right){
        return;
    }
    key = Arr[left];// 基准数
    l = left;
    r = right;
    while(l != r){
        // 顺序很重要，要仙踪右边开始找
        while(Arr[r] >= key && l<r){
            r--;
        }
        while(Arr[l] <= key && l<r){
            l++;
        }

        if(l < r ){
            t = Arr[l];
            Arr[l] = Arr[r];
            Arr[r] = t;
        }
    }
    Arr[left] = Arr[l];
    Arr[l] =key;
    quickSort(left,l-1);
    quickSort(l+1,right);
}

int main()
{
    int i;

    for(i = 0; i < 10; i++)
        printf("%d ", Arr[i]);
    printf("\n");

    quickSort(0, 9);

    for(i = 0; i < 10; i++)
        printf("%d ", Arr[i]);
    printf("\n");

    return 0;
}

