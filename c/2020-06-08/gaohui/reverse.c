#include <stdio.h>
static int m = 0;
static int k = 0;

void reverse(char *s);

int main()
{
  char s[]={"hello world"};
  reverse(s);
  s[k] = '\0';
  printf("反序的字符串为：%s\n",s);

  return 0;
}

void reverse(char *s)
{
  char c = '\0';
  if(s[m] != '\0')
  {
    c = s[m++];
    reverse(s);
  }
  if(k < m && c != '\0')
    s[k++] = c;
}