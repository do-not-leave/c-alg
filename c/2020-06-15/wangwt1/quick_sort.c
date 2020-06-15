#include <stdio.h>

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

//快速排序  
void quick_sort(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
        int i = l, j = r, x = s[l];  
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;    
            if(i < j)   
                s[i++] = s[j];  

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
                i++;    
            if(i < j)   
                s[j--] = s[i];  
        }  
        s[i] = x;  
        quick_sort(s, l, i - 1); // 递归调用   
        quick_sort(s, i + 1, r);  
    }  
} 


int main()
{
    int i;
    int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
    int N = 12;

    quick_sort(a, 0, N-1);

    for(i=0; i<N; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}