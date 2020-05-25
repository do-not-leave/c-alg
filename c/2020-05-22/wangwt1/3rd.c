#include <stdio.h>

unsigned invert(unsigned int x, int p, int n)
{
	return x^ (~(~0<<n)<<(p+1-n));
}

void main()
{
	unsigned a;
	a = invert(16, 2, 2);
	printf("%d", a);
}