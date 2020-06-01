#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
char *itob(int n, char s[], int b);
void self_print(char s[]);
int main()
{

  char *s;
  int n = 1235;
  itob(n, s, 10);
  self_print(s);
  return 0;
}

char *itob(int n, char *s, int b)
{
  int count = 0;
  do
  {
    s[count++] = n % b;
    n = n / b;
  } while (n != 0);
  s[count] = '\0';
  return s;
}
void self_print(char s[])
{
  int count = strlen(s);
  for (int i = count - 1; i >= 0; i--)
  {
    printf("%d", s[i]);
  }
}