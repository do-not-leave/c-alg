#include <stdio.h>
#include <math.h>


void itob(int n, char s[], unsigned b)
{
    int x = 0;
    while (n > pow(b, x))
    {
        x++;
    }
    printf("位数:%d\n", x);
    int mod;
    for(x -= 1; x >= 0; x--) {
        mod = n % b;
        if (mod < 10) {
            s[x] = mod + '0';
        } else {
            s[x] = mod - 10 + 'A';
        }
        n /= b;
        printf("当前值%d,余数%d\n", n, mod);
    }
}

int main()
{
    char s[20];
    int num = 734;
    itob(num, s, 16);
    printf("输入 %d, 结果 %s\n", num, s);

}

