#include<stdlib.h>
#include<stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(){
    char buffer[10];
    int i;

    for( i=2; i <= 20; ++i){
        itob(110, buffer, i);
        printf("110 %-2d:%s\n",i,buffer);
    }
    return 0;
}

void itob(int n, char s[], int b){
    static char digits[] = "0123456789ABCDEFGHJKLMNOPQRSTUVWXYZ";
    int i,sign;

    if( b < 2 || b > 36 ){
        fprintf(stderr,"cannot support base %d\n",b);
        exit(EXIT_FAILURE);
    }
    if((sign = n) < 0){
        n = -n;
    }
    i = 0;
    do {
        s[i++] = digits[n % b];
    }while ((n /= b) > 0);
    if(sign < 0){
        s[i++] = '-';
    }
    s[i] = '\n';
    reverse(s);
}

void reverse(char s[]){
    int c, i, j;
    for(i=0, j=strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
