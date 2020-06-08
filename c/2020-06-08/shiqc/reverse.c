#include <stdio.h>

void Reverse();
int main(){
    printf("反转字符串: ");
    Reverse();
    return 0;
}

void Reverse(){ 
    char c;
    c = getchar();
    if( c != '\n' && c  != EOF)
    {
        Reverse();
        printf("%c",c);
    }
} 