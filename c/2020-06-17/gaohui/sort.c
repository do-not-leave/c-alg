
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
 
int end_zeros( int* A, int nSize ){
	assert(A != NULL);
	int end = nSize-1;
	for(int i=0; i<end; i++){
		if(A[i]==0){
			while(A[end]==0) end--;
			int t = A[end];
			A[end] = A[i];
			A[i] = t;
		}
	}
	return end;//返回值为原数据中第一个元素为0的下标
}
 
/**
* 
* 快速排序
*/
int Funk(int* A, int nSize){
	assert(A != NULL);
	if(nSize<2) return 0;
	int split = A[0];//best random
	
	int i=1;
	int j=nSize-1;
	while(i<=j){
		while(A[i]<=split) i++;
		while(A[j]>split) j--;
		if(i<j){
			
			
				int t = A[i];
				A[i] = A[j];
				A[j] = t;
				
				i++;
				j--;
		}			
				
	}
	int t = A[i-1];//此时i所指元素大于split，而i-1所指元素小于split
	A[i-1] = A[0];//有序
	A[0] = t;
	
	for(int n=0; n<nSize; n++){
		printf("%d ",A[n]);
	}
	printf("\n");
	
	Funk(A, i-1);//0:(i-2)
	Funk(A+i, nSize-i);//i:(nSize-1)	
 
        return 0;
	
}
 
 
int Func(int* A, int nSize){
	//将0元素放置于数组尾部
	int res = end_zeros( A, nSize );
    Funk(A, res);
	return res;//返回值为原数据中第一个元素为0的下标
}
 
 
int main(){
	int A[10]={2,0,6,0,7,8,1,9,10,0};
	int res = Func(A, 10);

	
	for(int n=0; n<10; n++){
		printf("%d ",A[n]);
	}
	printf("\n");
	
	return 0;
}