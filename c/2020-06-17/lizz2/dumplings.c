#include<stdio.h>


int findZero(int a[],int num);
int moveZero(int a[],int num);

int main(){
	
	int a[] = {2,4,0,0,1,5,0,9,14,0}; 
	
// 	int res = SuperSort(a,10);
//	printf("\n下标为:%d",res);
	
    int index = moveZero(a,10);
    printf("\n下标为:%d",index);
    
    
	return 0 ;
}

int SuperSort(int a[],int num){
	int i=0;
	int index = -1;
	int j = num-1;
    while(i<j){
    	if(a[j] ==0){
    		j--;
    		continue;
		}
		if(a[i] == 0){
			if(index == -1){
			    index = i;	
			}
			a[i] =a[j];
			a[j] = 0;
			j--;
		}
		i++;
	}
	
	printf("重新排序后：\n");
	for(i=0;i<10;i++){
		printf("%d\t",a[i]);
	}
	if(index == -1){
		index =0;
	}
	return index;
}

int moveZero(int a[],int num){
    int res[num] ;
    int zeroNum =0;
    int i,j,m,n=0;
    int index =-1;
    for(i=0;i<num;i++){
    	if(a[i] != 0){
    		res[j]=a[i];
    		j++;
		}else{
			if(index == -1){
				index= i;
			}
			m++;
		}
	}
	for(i=0;i<m;i++){
		res[j] = 0;
		j++;
	}
	printf("\n moveZero重新排序后：\n");
	for(i=0;i<10;i++){
		printf("%d\t",res[i]);
	}
	return index;
}








