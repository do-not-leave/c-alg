#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x){
	int b ;
	for (b=0; x!=0; x &= (x-1)){
			b++;
	}
	return b;	
}
int main(){

	printf("%d",bitcount(5));
	return 0;
}
