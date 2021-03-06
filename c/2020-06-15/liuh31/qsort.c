#include "./qsort.h"


void m_qsort(int *a, int left, int right)
{
  if (left >= right) {
    return;
  }

  int mid_k = (left+right)/2;
  int start = left;
  swap_int(a+left, a+mid_k);

  for (int i = left + 1; i <= right; i++) {
    if (a[i] < a[left]) {
      start++;
      swap_int(a+start, a+i);
    }
  }
  swap_int(a+start, a+left);
  m_qsort(a, left, start - 1);
  m_qsort(a, start + 1, right);
}

void m1_qsort(int *a, int left, int right)
{
  if (left >= right) {
    return;
  }

  if ((right + 1 - left) <= QSORT_MIN_NUM) {
    m_insert_sort(a, left, right);
    return;
  }

  int mid_k = (left+right)/2;
  int start = left;
  swap_int(a+left, a+mid_k);

  for (int i = left + 1; i <= right; i++) {
    if (a[i] < a[left]) {
      start++;
      swap_int(a+start, a+i);
    }
  }
  swap_int(a+start, a+left);
  m1_qsort(a, left, start - 1);
  m1_qsort(a, start + 1, right);
}

void m_insert_sort(int *a, int left, int right)
{
  for (int i = left + 1; i <= right; i++) {
    for (int j = i; j > left; j--) {
      if (a[j] <= a[j-1]) {
        swap_int(a+j, a+j-1);
      } else {
        break;
      }
    }
  }
}

void print_int_array(int *a, int size)
{
  char c = ',';

  for (int i = 0; i < size; i++)
  {
    if (i == size - 1) {
      c = ' ';
    }
    printf("%d%c", a[i], c);
  }
  printf("\n");
}

void swap_int(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}