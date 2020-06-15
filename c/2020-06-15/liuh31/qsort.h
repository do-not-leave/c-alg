#include<stdio.h>
#include<stdlib.h>

#define QSORT_MIN_NUM 3
#define ARRAY_MAX_NUM 1000

void swap_int(int *a, int *b);
void m_qsort(int *a, int left, int right);
void m1_qsort(int *a, int left, int right);
void m_insert_sort(int *a, int left, int right);
void print_int_array(int *a, int size);