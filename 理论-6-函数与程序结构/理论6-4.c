//用递归实现标准库函数strlen(s)
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//请根据step4_main.c中主函数流程
//使用递归的方法补全此函数
int  mystrlen(char *s)
{
	/**********  Begin  **********/
    if (*s=='\0') {
        return 0;
    } 
    else {
        return 1 + mystrlen(s+1);
    }
    /**********  End  **********/
}
/*int main() {
	char s[100];
	int strlenth = 0;
	scanf("%s", &s);
	strlenth = mystrlen(s);
	printf("%d", strlenth);
	return 0;
}*/