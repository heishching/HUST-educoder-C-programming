//编写函数strnCpy(t,s,n)。它将字符数组s中的前n个字符复制到字符数组t中，并形成字符串
#include<stdio.h>

void strnCpy(char t[],char s[],int n){
	/**********  Begin  **********/
    for(int i=0;i<n;i++){
        t[i]= s[i];
    }
    t[n]='\0';
	/**********  End  **********/
}
/*#include"Step4_stu.h"
#define SIZE 100

int main()
{

	int n;
	char arr[SIZE];
	char out[SIZE];
	scanf("%[^\n]",&arr);
	scanf("%d",&n);
	strnCpy(out,arr,n);
	printf("%s",out);
	return 0;
}*/