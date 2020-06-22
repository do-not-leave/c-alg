#include <stdio.h>

#define SWAP(X,Y) X=X+Y;Y=X-Y;X=X-Y

//插入排序
int main() {
    int a[10] = {10,9,8,27,16,15,4,3,2,1};
    for (int i = 1; i < 10; i++) {
        int j = i;
        while ((j > 0) && a[j] < a[j - 1])
        {
            SWAP(a[j], a[j - 1]);
            j -= 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}