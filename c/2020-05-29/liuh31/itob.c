#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_LEN  100

char itoc(int n);
void itob(int n, char s[], int b);

int main() {
    int n = 0, b = 0, start = 1;
    char s[MAX_LEN];

    while (start) {
        printf("input: ");
        if (!scanf("%d, %d", &n, &b)) {
            printf("error\n");
            break;
        }
        itob(n, s, b);
        printf("output: %s\n0 to exit:", s);
        scanf("%d", &start);
        printf("\n");
    }
    return EXIT_SUCCESS;
}

void itob(int n, char s[], int b) {
    int t = 0, i = 0;
    int sign = 0;
    char tmp;
    if (n < 0) {
       sign = 1;
    }
    while (n != 0) {
        s[i++] = itoc((n % b));
        n = n / b;
    }
    if (sign == 1) {
        s[i++] = '-';
    }
    s[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        tmp = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = tmp;
    }
}

char itoc(int n) {
    n = abs(n);
    if (n < 0 || n > 36) {
       return '0';
    } else if (n <= 10) {
        return n + '0';
    } else {
        return n + 'A' - 10;
    }
}