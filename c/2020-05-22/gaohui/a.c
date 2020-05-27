#include <stdio.h>

int find(int arr[],int length){
    int ret = arr[0];
    for(int i = 0;i <length; i++){
        ret ^= arr[i];
    }
    return ret;
}


int find_num_once(int a[], int n)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < n; i++) 
		ret ^= a[i];
	return ret;
}

int main()
{
	int  n =7;
	if((n &2) == 2){
		//printf("n是个偶数");
	}else{
		//printf("%s\n","奇数" );
	}

	int x =1 ;
	int  y =2;

	x = x ^ y ;
	y = x ^ y ;
	x = x ^ y;

	int arr[] = {1,3,5,2,1,3,5,9};
	int tmp = find_num_once(arr,8);
	printf("%s %d\n","不重复的数字是",tmp);
	return 0;

}