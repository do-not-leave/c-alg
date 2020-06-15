
#include <stdio.h>
void sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while( i<j && key <= a[j])

        {
            j--;/*向前寻找*/
        }
         
        a[i] = a[j];     
        while(i < j && key >= a[i])
        {
            i++;
        }
         
        a[j] = a[i];
    }
     
    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
}

int main (){

    int a[10]= {1,2,3,4,54,25,23,21,78,10};
    int *p;
    p=&a[0];
    sort(p,1,10);

    for (int i=0;i <10;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}