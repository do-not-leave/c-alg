#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
int main()
{
	int i;
	unsigned a;
	printf("输入一个整数：");
	scanf("%d",&a);
	printf("对第二三四位求反：%u",invert(a,4,3));
	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	return (~(~0<<n) << (p-n+1)) ^ x;
}
