//输入正整数n，求s=1+2+3+4+...+n
#include<stdio.h>
int main()
{
	/**********  Begin  **********/
    int n,sum=0;
    scanf("%d",&n);
    sum=(n+1)*n/2;
    printf("%d",sum);
    
	/**********  Begin  **********/
    return 0;
}