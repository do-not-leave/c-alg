#include <stdio.h>

int bitCount(unsigned x)
{
    int b = 0;
    for (; x != 0; b++) {
        printf("%d\n", b);
        x &= (x-1);
    }

    return b;
}

int main()
{
    int a;
    a = bitCount(6);
    printf("结果：%d\n", a);
    return 0;
}
