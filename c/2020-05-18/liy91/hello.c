#include <stdio.h>
int reverse(char *str);
int main(){
  char str[] = "abcdefgh";
  reverse(str);
  return 0;
}

int reverse(char *str)
{
  if (str == NULL) 
  {
    return 0;
  }
  if (*str == '\0') 
  {
    return 0;
  }
  reverse(str + 1);
  printf("%c", *str);
  return 0;
}