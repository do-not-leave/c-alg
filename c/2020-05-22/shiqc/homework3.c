#include <stdio.h>
int invert(int x,unsigned int p,unsigned int n)
{
    return x ^ ((~(~0<<n) << (p+1-n)));
}

int  main()
{
    int i;
    // 65 :   0100 0001
    i=invert(65,2,1);// 0100 0 001  
    printf("%d\n",i);
    i=invert(77,2,1);
    printf("%d\n",i);
}

