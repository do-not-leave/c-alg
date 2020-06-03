#include <stdio.h>

void  sort(int a[],int l);
int main ()
{
    int a[] = {73,22,74,18,46,11,84,62,10,85};
    int l = sizeof(a)/sizeof(a[0]);
    sort(a,l);
    for (int i=0; i<l; i++)
    {
        printf("%d\n",a[i]);
    }
}

void sort(int a[],int l)
{
    int i,j,t;
    j = l - 1;
    while (j>0) {
        for (i=0; i<j; i++) {
            if (a[i] >= a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            if (i == j - 1) {
                j--;
            }
        }
    }
}