#include <stdio.h>

int bitCount(unsigned x)
{
    int b = 0;
    for (; x != 0; x >>= 1) {
        printf("%d\n", b);
        if (x & 01) {
            b++;
        }
    }

    return b;
}

int main()
{
    int a;
    a = bitCount(6);
    printf("%d", a);
    return 0;
}
