#include <stdio.h>

int SuperSort(int *a, int n);
void quick_sort(int s[], int l, int r);

int main()
{
    int arr[10] = {1,20,3,8,0,4,0,9,0,6};
    printf("排序前为：");
    for (int i =0; i<10; i++) {
        printf("%3d\t", arr[i]);
    }
    printf("\n");

    //调用函数
    int *p = arr;
    int pos = SuperSort(p, 10);
    printf("排序后为：");
    for (int i =0; i<10; i++) {
        printf("%3d\t", arr[i]);
    }
    printf("\n");
    printf("第一个0的位置为：%d\n", pos);
}

int SuperSort(int *a, int n)
{
    int sign=-1;
    int c = 0;
    int tmp[n];
    int j = 0;
    for (int i=0; i < n; i++) {
        //找到第一个0
        if (*a == 0 && sign == -1) {
            sign = i;
        }
        if (*a == 0) {
            tmp[n-c-1] = *a;
            c++;
        } else {
            tmp[j] = *a;
            j++;
        }
        *a++;
    }

    //对非0部分排序
    quick_sort(tmp, 0, j-1);

    for (int i=0; i<n; i++) {
        *(a - n + i) = tmp[i];
    }

    return sign;
}


//快速排序  
void quick_sort(int s[], int l, int r)  
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
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