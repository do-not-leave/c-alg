#include <stdio.h>
void escape(char s[],char t[]){
    int i=0,j=0;
    while(t[i]){
        switch(t[i]){
            case '\n':
                s[j++]='\\';
                s[j++]='n';
                break;
            case '\t':
                s[j++]='\\';
                s[j++]='t';
                break;
            default:
                s[j++] = t[i];
        }
        ++i;
    }
    s[j]='\0';
}

int main(){
	char t[30]= "hello \t word \n";
	char s[30]= "";
	int i = 0;
	escape(s,t);
	while(s[i]){
		printf("%c",s[i++]);
	}

	return 0;
}
