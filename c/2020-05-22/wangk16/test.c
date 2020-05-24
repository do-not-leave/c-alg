#include <stdio.h>

int invert(unsigned x, int p, int n);

int main()
{
	int i;
	unsigned a;
	printf("in:");
	scanf("%d",&a);
	printf("res:%d",invert(a,4,3));
	return 0;
}

int invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 -n));
}

int invert2(int x, int p, int n) {
    return x ^ ((~0 << (p + 1 - n)) ^ (~0 << (p + 1)));
}
