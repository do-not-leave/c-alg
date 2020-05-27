#include <stdio.h>

void copy(char to[], char form[]);
void escape(char to[], char form[]);
void vescape(char to[], char form[]);

int main()
{
  char to[100];
  char to1[100];
  char form[100] = "abc\nscd\a\na";
  printf("%s\n", form);
  escape(to, form);
  printf("%s\n", to);
  vescape(to1, form);
  printf("%s\n", to1);
}
void copy(char to[], char form[])
{
  int i = 0;
  while ((to[i] = form[i]) != '\0')
  {
    ++i;
  }
}

void escape(char to[], char form[])
{
  int i = 0;
  int j = 0;
  while (form[i] != '\0')
  {
    switch (form[i])
    {
    case '\n':
      to[j++] = '\\';
      to[j++] = 'n';
      break;
    case '\t':
      to[j++] = '\\';
      to[j++] = 't';
    case '\a':
      to[j++] = '\\';
      to[j++] = 'a';
    default:
      to[j++] = form[i];
      break;
    }
    ++i;
  }
}

void vescape(char to[], char form[])
{
  int i = 0;
  int j = 0;
  while (form[i] != '\0')
  {
    switch (form[i])
    {
    case '\\':
      break;
    default:
      to[j++] = form[i];
      break;
    }
    ++i;
  }
}