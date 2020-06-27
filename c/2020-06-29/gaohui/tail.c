#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFSIZE 512

int main(int argc,char **argv)
{
    char c;
    int line = 10;
    int count = 0;
    char buffer[BUFFSIZE][BUFFSIZE];

    //如果有-n，就将line的默认值改了。这里有错误默认是会自动提示的。
    while((c=getopt(argc,argv,"n:"))!=-1)
    {
        int x = atoi(optarg);
        line = x;
    }
    char *path = argv[optind];
    FILE *fp;
    int index = 0;
    //如果文件打开不成功，肯定是文件没找到，就报错
    if((fp = fopen(path,"r")) == NULL)
    {
        printf("File dosen't exit!");
        return -1;
    }

    //下面就是前面讲的思路了，读取文件保存到数组
    while(!feof(fp))
    {
        count++;
        fgets(buffer[index],BUFFSIZE,fp);
        if(index+1 >= line)
        {
            index = 0;
        }
        else{
            index++;    
        }
    }

    //记得关闭fp
    fclose(fp);
    int i;
    if(count < line)
    {
        line = count;
    }
    //因为前面是用的++，多加了1
    if(index != 0)
    {
        index--;
    }
    for(i = 0;i<line;i++)
    {
        printf("%s",buffer[index++]);
        if(index >= line)
        {
            index = 0;
        }
    }

}