#include<stdio.h>

void  reverse(char str[],int len);


#define LEN_MAX  100

int main(){
	char str[LEN_MAX];
	int len = 0;
    char c ;
    while((c = getchar()) != EOF){
    	if(c == '\n'){
		    str[len++] = '\0';
		    reverse(str,len);
		    len = 0;
		}else{
		    str[len++] = c;
		}
	}
	return 0;
} 

void reverse(char str[],int len){
	  char line[LEN_MAX];
	  int i;
	  int j = -1;
	  for(i= 1;len >= i;i++){
	  	if(i == 0){
	  		line[j++] ='\0';
		  }else{
		  	line[j++] = str[len-i];
		  }
	  	
	  }
      printf("反转后字符为:%s\n",line);
}
