#include<stdio.h>
#include<stdlib.h>

int invert(int x, int p, int n);
int invert2(int x, int p, int n);
unsigned getbits(int p, int n);

int main() {
    int input, rpos = 0, len = 0;
    int goon = 1;

    while (goon) {
        printf("输入(值, 右数位置, 长度):");
        scanf("%d, %d, %d", &input, &rpos, &len);
        if (len <= 0 || rpos < len) {
            printf("参数不合法,位置大于长度,长度大于0\n");
        } else {
            printf("结果: %d\n", invert(input, rpos, len));
            printf("结果: %d\n输入0结束:", invert2(input, rpos, len));
        }
    
        scanf("%d", &goon);
    }

    return EXIT_SUCCESS;
}

int invert(int x, int p, int n) {
    return x ^ ((~0 << (p + 1 - n)) ^ (~0 << (p + 1)));
}

int invert2(int x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 -n));
}