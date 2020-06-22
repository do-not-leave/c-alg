#include<stdio.h> 

void csort(int a[],int num );

int  main(){
	int a[10] = {1,4,3,5,6,8,9,0,2,7};
	csort(a,10);
	return 0;
}

void csort(int a[],int num){
	int pos, cur,i =0;
    for (i = 1; i < num; i++)
         {
            pos = i -1 ;    //有序序列的最后一个元素位置
            cur = a[i];    //保存待排序元素的值
            while ( pos >= 0 && a[pos] > cur)
               {
                  a[pos + 1] = a[pos];
                  pos--;
               }
            a[pos + 1] = cur;    //将待排序元素插入数组中
        }
    for(i=0;i<num;i++)
         {
		    printf("%d",a[i]);
	     }
}
