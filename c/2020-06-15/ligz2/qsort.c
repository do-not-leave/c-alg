#include <stdio.h>

void qsort(int a[], int l, int r);
void print_a(int a[], int l);
void swap_int(int *a,  int *b);
int main()
{
    int a[10] = {1,5,3,9,22,99,55,7,6,86};
    print_a(a,10);
    qsort(a, 0, 9);
    print_a(a,10);
}

void qsort(int a[], int l, int r) {
    if (l >= r) {
        return;
    }
    //设定中间数
    int pos = (l+r)/2;
    //记录中间数位置
    int mid_v = a[pos];
    //设定下次排序分界点
    int start = r;
    swap_int(&a[r], &a[pos]);
    for(int i=r-1;i>=l;i--) {
        if (a[i] > mid_v) {
            swap_int(&a[i], &a[start]);
            start--;
        }
    }
    print_a(a,10);
    qsort(a, l, start-1);
    qsort(a, start+1, r);
}

void  print_a(int a[], int l) {
    for(int i=0; i<l; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap_int(int *a,  int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
