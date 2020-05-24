#include <stdio.h>
int bitCount(unsigned x);
int main()
{
    printf("bit count: %d\n", bitCount(3));
    return 0;
}

int  bitCount(unsigned x)
{
    int count = 0;
    while (x != 0)
    {
        x &= (x - 1);
        count++;
    }
    return count;
}