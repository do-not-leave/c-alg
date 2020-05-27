#include<stdio.h>

void test(int s);

int main(){
    test(2);
}

void test(int s)
{
    switch (s)
    {
        case 0:
            printf("target 0\n");
            break;
        case 1:
            printf("target 1\n");
            break;
        case 2:
            printf("target 2\n");
            
        case 3:
            printf("target 3\n");
            break;            
        
        default:
            break;
    }
}