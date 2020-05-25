#include <stdio.h>

int bitcount(unsigned x);

int main()
{
  int x = 9999;
  printf("%d", bitcount(x));
  return 0;
}

int bitcount(unsigned x)
{
  int i = 0;
  while (x)
  {
    x &= x - 1;
    i++;
  }
  return i;
}
