#include<stdio.h>


char itob(int n,char s[],int b );
char reverse(char s[]);

int main(){
	
	int n=5,b=2;
	char s[1000];
	
	printf(itob(5,s,2));
//	itob(5,s,2);
	
	return 0;
}

 char itob(int n,char s[],int b ){
 	int res = 0,i=0,num=1,yushu;
 	switch (b){
	 case 2:
	 case 8:	
	 	while(1){
	 		yushu = n%b;
	 		n=n/b;
	 		s[i++] = yushu;
	 		if(n<b){
	 			s[i++] = n;
	 			break;
			 }
		 }
        break;
	 case 16:
	 	while(1){
	 		yushu = n%b;
	 		n=n/b;
	 		if(yushu < 10){
	 			s[i++] = yushu;
			 }else{
			    s[i++] = (yushu - 10) + 'A';
			 }
	 		if(n<b){
	 			s[i++] = n;
	 			if(n < 10){
	 			s[i++] = n;
			 }else{
			    s[i++] = (n - 10) + 'A';
			 }
	 			break;
			 }
		 }
        break;	   
	 }
	 return reverse(s);
 }
 
char reverse(char s[])
{  
    char res[1000];     
    int c, i, j = 0;
    for (i = strlen(s)-1;i>0; i--) {
            res[j++] = s[i];
    }
    return res;
}
 
 
