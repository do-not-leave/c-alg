#include<stdio.h>

void escape(char s[], char t[]);


int main(){
	int i=0;
	char t[20] = "123 56 78";
	char s[50];
    escape(s,t);
}


void escape(char s[], char t[]){
	int i,j =0;
	int  num = strlen(t); 
	for(i=0;i<num;i++){
		switch (t[i]){
		   case '\n':
		        s[j++] = '\\';
		        s[j++] = 'n';
		        break;
			case '\t':
		        s[j++] = '\\';
		        s[j++] = 't';
		        break;
			case '\a':
		        s[j++] = '\\';
		        s[j++] = 'a';
		        break;
			case '\v':
		        s[j++] = '\\';
		        s[j++] = 'v';
		        break;
			default:
			    s[j++] = t[i];	
			break;				
		}
			
	}
	printf("%s",s);
}
