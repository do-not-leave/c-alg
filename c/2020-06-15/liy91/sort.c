#include <stdio.h>

void myprint(int *s, int n);
void quickSort(int *s, int l, int r);
void quick_sort(int *s, int l, int r);

int main()
{
  int s[] = {1, 3, 4, 2, 6, 10};
  quickSort(s, 0, 5);
  myprint(s, sizeof(s) / sizeof(int));
  return 0;
}

void quickSort(int *s, int l, int r)
{

  if (l < r)
  {
    int i = l;
    int j = r;
    int x = s[l];
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
      while (i < j && s[i] < x)
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
}

//快速排序
void quick_sort(int s[], int l, int r)
{
  if (l < r)
  {
    //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
    int i = l, j = r, x = s[l];
    while (i < j)
    {
      while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
        j--;
      if (i < j)
        s[i++] = s[j];

      while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
        i++;
      if (i < j)
        s[j--] = s[i];
    }
    s[i] = x;
    quick_sort(s, l, i - 1); // 递归调用
    quick_sort(s, i + 1, r);
  }
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
