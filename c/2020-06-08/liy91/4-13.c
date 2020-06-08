
#include <stdio.h>

void recursion_reverse(char *s, int len);
int str_len(char *s);

int main()
{
  int len;
  char s[10] = "abcdefgh";

  len = str_len(s);
  recursion_reverse(s, len);
  printf("%s\n", s);

  return 1;
}

int str_len(char *s)
{
  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}

void recursion_reverse(char *s, int len)
{
  int temp, i;

  if (*(s + 1) != '\0')
  {
    recursion_reverse(s + 1, len - 1);
  }
  if (len > 1)
  {
    temp = *s;
    for (i = 0; i < len - 1; i++)
      *(s + i) = *(s + i + 1);
    *(s + len - 1) = temp;
  }

  return;
}