#include <stdio.h>

void myprint(int *s, int n);
void insert_sort(int *s, int n);

int main()
{
  int s[] = {1, 3, 4, 2, 6, 10};
  insert_sort(s,  5);
  myprint(s, sizeof(s) / sizeof(int));
  return 0;
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

void insert_sort(int *arr, int len)
{
  int tmp;
  int i;
  int j;
  for (i = 1; i < len; i++)
  {
    tmp = arr[i];
    for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = tmp;
  }
}
