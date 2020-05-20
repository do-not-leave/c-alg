#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int htoi(char *s);

int main(){
    char *b;
    gets(b);
    int ret = htoi(b);
    printf("%s转换为10进制结果是%d\n",b,ret);
    return 0;
}

int htoi(char *s){
    int len = strlen(s);
    int mi;
    int temp;
    int total = 0;
    if(len < 3){
        printf("至少三位！\n");
        exit(1);
    }

    if (s[0] != '0' || (s[1] != 'x' && s[1] != 'X')){
        printf("开头必须是0x或是0X！\n");
        exit(1);
    }

    for (int i = len - 1; i > 1; i--){
        mi = len - 1 - i;
        if (s[i] >= '0' && s[i] <= '9'){
            temp = (s[i] - '0') * pow(16 , mi);
        }else if(s[i] >= 'a' && s[i] <= 'f'){
            temp = (s[i] - 'a' + 10) * pow(16 , mi);
        }else if(s[i] >= 'A' && s[i] <= 'F'){
            temp = (s[i] - 'A' + 10) * pow(16 , mi);
        }else{
            printf("第%d位是%c,不合法！\n",mi + 1,s[i]);
            exit(1);
        }
        total += temp;
        printf("i:%d|s[i]:%c|mi:%d|temp:%i|total:%d\n",i,s[i],mi,temp,total);
    }

    return total;
}


