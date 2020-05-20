#include <stdio.h>
#define MAXLENGTH 128
void swap(char string[],int len);
int main()
{
    char string[MAXLENGTH],c;
    int realLen = 0;
    while((c=getchar())!=EOF){
        string[realLen] = c;
        if(realLen == MAXLENGTH - 1){
            break;
        }
        realLen++;
    }
    printf("reallen:%d\n",realLen);
    
    swap(string,realLen);
    for(int i=0;i<realLen;i++){
        printf("%c",string[i]);
    }
    printf("\n");
    return 0;
}

void swap(char string[],int len){
    char temp;
    int i;
    for(i=0;i<len/2;i++){
        temp = string[i];
        string[i] = string[len-i-1];
        string[len-i-1] = temp;
    }
}
