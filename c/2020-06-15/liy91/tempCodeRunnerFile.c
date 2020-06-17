#include <stdio.h>

void myprint(int *s, int n);
void quickSort(int *s, int l, int r);
int main()
{
  int s[] = {1, 3, 4, 2, 6, 10};
  quickSort(s, 0, 6);
  myprint(s, sizeof(s) / sizeof(int));
  return 0;
}

void quickSort(int *s, int l, int r)
{
  int i = l;
  int j = r;
  int x = s[0];
  while (i < j)
  {
    while (i < j && s[j] >= x)
    {
      j--;
    }
    if (i < j)
    {
      s[i++] = s[j];
    }
    while (i < j && s[i] <= x)
    {
      i++;
    }
    if (i < j)
    {
      s[j--] = s[i];
    }
  }

  s[i] = x;
  quickSort(s, l, i - 1);
  quickSort(s, i + 1, r);
}

void myprint(int *s, int n)
{
  int *p;
  for (p = s; p < s + n; p++)
  {
    printf("%d ", *p);
  }
  printf("\n");
}
