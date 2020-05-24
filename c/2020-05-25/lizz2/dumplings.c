#include <stdio.h> 

int bitcount(unsigned x);


int main(){
	int x = 3;
	printf("%d",bitcount(x)); 
	return 0;
}


int bitcount(unsigned x ){
	int b;
	for(b=0;x!=0;x&=(x-1)){
		b++;
	}
	return b;
}
