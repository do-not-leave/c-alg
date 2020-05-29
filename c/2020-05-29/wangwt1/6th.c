#include <stdio.h>
#include <math.h>

void itob(int n, char s[], unsigned b)
{
    //确定字符串位数
    int x = 0;
    while (n > pow(b, x))
    {
        x++;
    }
    printf("位数:%d\n", x);

    int mod;
    //字符串末尾
    s[x] = '\0';
    for (x = x-1; x >= 0; x--) {
        mod = n % b;
        if (mod < 10) {
            s[x] = mod + '0';
        } else {
            s[x] = mod - 10 + 'A';
        }
        n /= b;
        printf("当前值x %d, n %d, 余数%d\n", x, n, mod);
    }
}

int main()
{
    char s[20];
    int num = 10;
    unsigned base = 16;
    itob(num, s, base);
    printf("输入%d，转换为%d进制，结果 %s\n", num, base, s);

}

