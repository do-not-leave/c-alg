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
            pos = i -1 ;    //�������е����һ��Ԫ��λ��
            cur = a[i];    //���������Ԫ�ص�ֵ
            while ( pos >= 0 && a[pos] > cur)
               {
                  a[pos + 1] = a[pos];
                  pos--;
               }
            a[pos + 1] = cur;    //��������Ԫ�ز���������
        }
    for(i=0;i<num;i++)
         {
		    printf("%d",a[i]);
	     }
}
