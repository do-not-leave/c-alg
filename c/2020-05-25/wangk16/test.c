#include <stdio.h>
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;        
}       

int main()
{
    int res;
    res = bitcount(5);
    printf("res:%d",res);
    return 0;
}