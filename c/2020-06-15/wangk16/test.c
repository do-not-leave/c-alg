#include <stdio.h>
int qusort(int s[],int start,int end)   
{
    int i,j;    
    i=start;    
    j = end;    
    s[0]=s[start];    
    while(i<j)
    {
        while(i<j&&s[0]<s[j])
        j--;    
        if(i<j)
        {
            s[i]=s[j];    
            i++;    
        }
        while(i<j&&s[i]<=s[0])
            i++;    
        if(i<j)
        {
            s[j]=s[i];    
            j--;    
        }
    }
    s[i]=s[0];    
    if (start<i)
        qusort(s,start,j-1);    
    if (i<end)
        qusort(s,j+1,end);
    return 0;
}
int main()
{
    int a[11], i;    
    printf("in 10 num:\n");
    for(i=1;i<=10;i++)
        scanf("%d",&a[i]);    
    qusort(a,1,10);    
    printf("result:\n");
    for(i=1;i<=10;i++)
        printf("%5d",a[i]);    
    printf("\n");
    return 0;
}