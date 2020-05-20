#include <stdio.h>
#define MAX_LENGTH 100
void reverse(char str[], int len);
int main ()
{
    char str[MAX_LENGTH];
    char input;
    int len = 0;
    while ((input = getchar()) != EOF) {
        if (input == '\n'){
            str[len] = '\0';
            break;
        }
        if (len > MAX_LENGTH) {
            break;
        }
        str[len] = input;
        len++;
    }
    printf("reverse before: %s\n", str);
    reverse(str, len);
    printf("reverse after: %s\n", str);
    return 1;
}

void reverse(char str[], int len) {
    char l,r;
    for(int i = 0; i < len/2; i++) {
        l = str[i];
        r = str[len-i-1];
        str[i] = r;
        str[len-i-1] = l;
    }
}