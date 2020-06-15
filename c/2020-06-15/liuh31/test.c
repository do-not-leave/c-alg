#include "./qsort.h"

int main() {
  int data[6] = {6, 2, 3, 5, 4, 1};
  print_int_array(data, 6);
  m_qsort(data, 0, 5);
  print_int_array(data, 6);
  return EXIT_SUCCESS;
}