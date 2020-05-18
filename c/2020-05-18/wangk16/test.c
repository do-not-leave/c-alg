#include <stdio.h>
#include <string.h>
int main()
{
   char str[100];
   int i;
   char res[100];
   int len;
   int j;
 
   gets( str );
 
   printf( "\nYou entered: %s",str);
   len = strlen(str);
   j = 0;
   for (int i = len - 1; i >= 0; i--)
	{
        if(j <= len -1){
            res[j] = str[i];
            j++;
        } 
	}
	printf( "\n反转结果 %s",res);

   return 0;

}
