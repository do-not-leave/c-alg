#include  "common.h"
#include <stdio.h>

int main()
{
    printf("%d\n",geta());
    printf("%c\n",getb());
    // extern int ext_a[];
    // for (int i=0;i<=9;i++) {
    //     printf("%d ",ext_a[i]);
    // }
    // getcs();
    // extern int a;
}

int a=10;
char b = 'm';
int geta() {
    return a;
}
char getb() {
    return b;
}