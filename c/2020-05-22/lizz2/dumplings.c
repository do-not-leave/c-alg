#include <stdio.h>

int invert2(int x, int p, int n);
int main(){
	int n ,res;
	//100011
	n = 35;
//	res = invert2(n,2,3);
//	// 36  100100
//	printf("%d",res);

	res = invert2(n,3,3);
	// 45  101101
	printf("%d",res);
	
	return  0;
}

int invert2(int x, int p, int n) {
    return (~(~0 << n) << (p + 1 -n)) ^ x;
}
