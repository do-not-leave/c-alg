#include <stdio.h>

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 1)
            b++;
    return b;
}

int nbcount(unsigned x)
{
    if (x == 0) {
        return 0;
    }
    x &= (x-1);
    return nbcount(x) + 1;
}
int main()
{
    unsigned int in;
    scanf("%u", &in);
    printf("%d \n", bitcount(in));
    printf("%d nb\n", nbcount(in));

}