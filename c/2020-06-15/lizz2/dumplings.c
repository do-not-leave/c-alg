#include<stdio.h>

 int qsort(int s[]);
 int Merge(int left[],int num ,int right[]);
 
 int main(){
 	int s[7] = {2,5,6,1,3,8,7};
// 	printf("%d",qsort(s));
 	qsort(s);
 	return 0;
 }
 int qsort(int s[]){
 	int i,num,len = 1;
 	len = sizeof(s)/sizeof(s[0]);
 	printf("%d",len);
 	int left[10];
	int right[10];
	int res[100];
	
	int m,n=0;
 	if(len <= 1){
 		printf("%d",s);
 		return s;
	}
	num = s[0];
	for(;i<len;i++){
		if(num > s[i]){
			left[m] = s[i];
			m++;
		}else{
		    right[n] = s[i];
		    n++;
		}
	}
	printf("%d \n %d",s,len);
	return 0; 
//	left = qsort(left);
//	right = qsort(right);
//	res = Merge(left,num,right);
//	return right;
 }
 
 
 int Merge(int left[],int num ,int right[]){
 	int res [10] ;
 	 int index,loop = 0;
 
   for(loop = 0; loop < strlen(left); loop++) {
      res[index] = left[loop];
      index++;
   }
 
  res[index] = num;
  index++;
   for(loop = 0; loop < strlen(right); loop++) {
      res[index] = right[loop];
      index++;
   }
 	return res;
 }
 
 
