#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int numberic = 0, reverse = 0;

  if (argc > 1) {
    for (int i = 0; i < argc - 1; i++) {
      if (strcmp(argv[i], "-n") == 0) {
        numberic = 1;
      } else if (strcmp(argv[i], "-r") == 0) {
        reverse = 1;
      }
    }
  }

  return EXIT_SUCCESS;
}