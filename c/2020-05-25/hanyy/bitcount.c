#include <stdio.h>

int bitcount(unsigned x){
	int a;
	for (a=0; x!=0; x &= (x-1)){
		a++;
	}
	return a;	
}
int main(){
	printf("%d",bitcount(5));
	return 0;
}
