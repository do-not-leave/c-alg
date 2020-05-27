#include <stdio.h>
#include <math.h>

/*
将16进制单个字符转换为10进制数字
*/
int h2d(char s) {
    // printf("%c\n", s);
    if (s >= '0' && s <= '9') {
        return s - '0';
    }
    if (s >= 'a' && s <= 'f') {
        return s - 'a' + 10;
    }
    if (s >= 'A' && s <= 'F') {
        return s - 'A' + 10;
    }

    return -1;
}

/*
将16进制字符串转换为10进制数字
*/
float htoi(int str[], int len) {
    float sum;
    int i, w, num;
    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        i = 2;
    } else {
        i = 0;
    }
    w = len - i;
    if (w <= 0) {
        return -1;
    }

    sum = num = 0;
    // printf("字符长度，%d\n", w);
    for (; i < len; i ++) {
        num = h2d(str[i]);
        // printf("字符%d：%c,数字:%d\n", i, str[i], num);
        if (num == -1) {
            return num;
        }
        sum += (pow(16, w-i-1) * num);
        // printf("sum= %.0f\n", sum);
    }
    // printf("sum= %.0f\n", sum);
    
    return sum;
}

// int* resetChar(int str[], int l) {
//     int i;
//     for (i = 0; i < l; i++) {
//         str[i] = 0;
//     }

//     return &str;
// }

void getChar(int s[], int l) {
    for (int i = 0; i < l; i++)
    {
        printf("%c", s[i]);
    }
}


int main() {
    int s[100];
    int l = 0;
    int c;
    float sum = 0;
    int needReset = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n') {
            if (l == 0) {
                continue;
            }
            sum = htoi(s, l);
            printf("您输入的字符串为：");
            getChar(s, l);
            printf("\n十进制结果为：%.0f\n\n", sum);

            l = 0;
            //重置数组
            for (int i = 0; i < l; i ++) {
                s[i] = 0;
            }
            needReset = 0;
            continue;
        }

        //进行输入校验
        if (l == 1) {
            if (s[0] == '0') {
                if (c != 'x' || c != 'X') { 
                    printf("字符: %c %c, ascii: %d, %d\n", s[0], c, s[0], c);
                    needReset = 1;
                    printf("1111\n");
                }
            } else {
                if (h2d(c) == -1) {
                    needReset = 1;
                    printf("22\n");
                }
            }
        } else {
            if (h2d(c) == -1) {
                needReset = 1;
                printf("33\n");
            }
        }

        //重置
        if (needReset > 0) {
            printf("您输入的字符不合法\n");
            l = 0;
            //重置数组
            for (int i = 0; i < l; i ++) {
                s[i] = -1;
            }

            //重置标记
            needReset = 0;
            continue;
        }
        
        if (l > 100) {
            printf("最多允许输入100个字符,请重新输入\n");
            l = 0;
            //重置数组
            for (int i = 0; i < l; i ++) {
                s[i] = -1;
            }
            needReset = 0;
        }

        s[l] = c;
        l++;
        
    }

    printf("退出\n");
    return 0;
}