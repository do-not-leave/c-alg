#include<stdio.h>
#include<stdlib.h>

void shell_sort(int *s, int len);

int main()
{
  int len = 6;
  int a[6] = {3, 8, 9, 2, 4, 10};

  shell_sort(a, len);
  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }


  return EXIT_SUCCESS;
}

void swap_int(int *a, int *b)
{
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void shell_sort(int *s, int len)
{
  for (int step = len / 2; step >= 1; step = step / 2) {
    for (int i = 0; i < len; i += step) {
      for (int j = i; j > 0; j -= step) {
        if (s[j] < s[j-step]) {
          swap_int(s+j, s+j-step);
        }
      }
    }
  }
}