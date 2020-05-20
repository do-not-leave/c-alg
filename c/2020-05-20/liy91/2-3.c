#include <stdio.h>
#include <ctype.h>
int atoi(char *str);
int htoi(char *str);

int main()
{
  char str[] = "0x7Bce";
  int a = htoi(str);
  printf("%d", a);
  return 0;
}

int atoi(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}

int htoi(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] != '\0'; ++i)
  {
    if (i == 0 && s[i] != '0')
    {
      return -1;
    }

    if (i == 1 && s[i] != 'x' && s[i] != 'X')
    {
      return -2;
    }
    if (i > 1)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        n = 16 * n + (s[i] - '0');
      }
      if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
      {
        
        n = 16 * n + (tolower(s[i]) - 'a' + 10);
      }
    }
  }
  return n;
}