#include <stdio.h>

unsigned  int getbits(unsigned x, int p, int n);

int main()
{
  unsigned int x = 10110101;
  int p =4;
  int n = 3;
  printf("%d",getbits(x,p,n));
}

unsigned int getbits(unsigned int x, int p, int n)
{
  return ~0;
  return (x >> (p + 1 - n) & ~(~0 << n));
}