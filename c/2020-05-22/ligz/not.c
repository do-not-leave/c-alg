#include <stdio.h>

int bitnot(int input, int start, int offset);

int main(){
    int input,start,offset,res;
    printf("输入整数\n");
    scanf("%d", &input);
    
    printf("输入起始位\n");
    scanf("%d", &start);
    printf("输入取反的个数\n");
    scanf("%d", &offset);
    res = bitnot(input, start, offset);
    printf("计算结果%d",res);
}

int bitnot(int input, int start, int offset) {
    //移位得出要取反的位置为1
    //用原值和移位值取异或操作
	return (~(~0<<offset) << (start-offset+1)) ^ input;
}