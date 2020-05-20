#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int htoi(char line[], ssize_t line_len);

int main() {
    char *line = NULL;

    size_t mem_len = 0;
    ssize_t line_len;

    printf("请输入十六进制数:");
    while ((line_len = getline(&line, &mem_len, stdin)) != -1) {
        printf("十进制数: %d\n\n", htoi(line, line_len));
        printf("请输入十六进制数:");
    }

    return EXIT_SUCCESS;    
}

int htoi(char line[], ssize_t line_len) {
    int result = 0;
    int pos = 0;
    if (line_len > 1) {
        char tmp;
        for (int i =  line_len - 2; i >= 0; i--) {
            tmp = line[i];
            if (tmp == 'x' || tmp == 'X') {
                break;
            } else if (tmp >= '0' && tmp <= '9') {
                result += (tmp - '0') * pow(16, pos);
                pos++;
            } else if (tmp >= 'a' && tmp <= 'f') {
                result += (tmp - 'a' + 10) * pow(16, pos);
                pos++;
            } else if (tmp >= 'A' && tmp <= 'F') {
                result += (tmp - 'A' + 10) * pow(16, pos);
                pos++;
            }
        }
    }

    return  result;
}