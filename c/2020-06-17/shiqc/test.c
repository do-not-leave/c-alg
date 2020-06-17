#include<stdio.h>


int main()
{

    char msg[] ="hello world";
    char *pmsg ="hello world";
    msg[3] = 'q';
    printf("%s\n",msg);
    printf("%s",pmsg);
    // pmsg[3] = 'q'; // 错误（Segment Fault）
    return 0;
}

/*
   它们最根本的区别是在内存中的存储区域不一样，字符数组存储在全局数据区或栈区，
   第二种形式的字符串存储在常量区。
   全局数据区和栈区的字符串（也包括其他数据）有读取和写入的权限，而常量区的字符串（也包括其他数据）只有读取权限，没有写入权限 
*/