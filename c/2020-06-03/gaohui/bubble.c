
#include <stdio.h>
int main(void){
    int N=8;
    int sum=0;
    int array[]={5,8,6,3,9,2,1,7};
    
    for(int i=0;i<N;i++){
        int  isSorted=1;
        for(int j=0;j+i<N-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted){
            break;
        }
        sum++;
    }
 
    for(int k=0;k<N;k++){
        printf("%d ",array[k]);
    }
    printf("\n");
    printf("交换的次数为:%d",sum);
    printf("\n");
    return 0;
}
