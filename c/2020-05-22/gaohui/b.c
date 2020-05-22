#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void find_num(int arr[], int sz)
{
	int i = 0;
	int pos = 0;
	int tmp = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < sz; i++)
	{
		tmp ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (1 == ((tmp >> i)&1))
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (1 == ((arr[i] >> pos)&1))
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("x = %d, y = %d", x, y);
}

int main()
{
	int arr[] = { 1, 2, 3, 1, 2, 3, 6, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]); //求出数组的长度
	find_num(arr, sz);
	return 0;
}