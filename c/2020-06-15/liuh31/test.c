#include "./qsort.h"

int main() {
  int len = 0;
  int data[ARRAY_MAX_NUM];
  int sort_type = 1;

  int start_flag = 1;

  while (start_flag) {
    start_flag = 0;
    printf("input length: ");
    if (scanf("%d", &len)) {
      printf("input data: ");
      for (int i = 0; i < len; i++) {
        if (!scanf("%d", &data[i])) {
          goto STOP;
          break;
        }
      }
      printf("input sort type: ");
      if (!scanf("%d", &sort_type)) {
        sort_type = 1;
      }
      switch (sort_type) {
        case 1:
          m_qsort(data, 0, len-1);
          break;
        case 2:
          m1_qsort(data, 0, len-1);
          break;
        default:
          m_qsort(data, 0, len-1);
      }

      printf("output data: ");
      print_int_array(data, len);
      printf("input 1 to continue: ");
      if (!scanf("%d", &start_flag)) {
        start_flag = 0;
        goto STOP;
        break;
      }
      printf("\n\n");
    } else {
      goto STOP;
      break;
    }
  }

STOP:
  printf("\nstop\n");
  
  return EXIT_SUCCESS;
}