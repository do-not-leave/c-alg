#include<stdio.h>
#include<stdlib.h>

/*
 * 
 * 给定一个整型参数，统计其二进制表示中1的个数
 * 例如：假设一个整型为8bit，整型数120的二进制表示为：01111000，其中1的个数为4
 * 
 */

int bitcount(unsigned x);
int m_bitcount(unsigned x);

int main() {
  int goon = 1;
  while (goon) {
    unsigned input;
    printf("请输入:");
    scanf("%u", &input);
    printf("bitcount结果:%d\n", bitcount(input));
    printf("m_bitcount结果:%d\n输入0结束:", m_bitcount(input));
    scanf("%d", &goon);
  }
  return EXIT_SUCCESS;
}

int bitcount(unsigned x) {
  int cnt = 0;
  for ( ;x != 0; x >>= 1) {
    if (x & 01 == 1) {
      cnt++;
    }
  }
  return cnt;
}

int m_bitcount(unsigned x) {
  int cnt = 0;
  for (; x != 0; x = x&(x-1)) {
    cnt++;
  }
  return cnt;
}