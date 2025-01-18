/*编写一个测试一个串是否为回文的递归函数，是回文，函数返回1；不是回文，返回0。并且在主函数中调用该函数，判断输入的字符串是否为回文串。

回文是正读和反读都一样的串，例如：“abcba” 和“otto”就是回文。主函数中若输入的字符串是回文，则输出“Yes”，否则输出“No”。*/
#include<stdio.h>
#include<string.h>
#define SIZE 100
int isPalindrome(char arr[],int len);
int main()
{
	/**** 输入字符串,调用函数isPalindrome判断是否为回文串，然后输出结果 *******/ 
    /**********  Begin ***********/
    char arr[100];
    int len;
    scanf("%[^\n]",&arr);
    len=strlen(arr);
    switch(isPalindrome(arr,len)){
        case 0:printf("No"); break;
        case 1:printf("Yes"); break;
    }
	/**********  End  **********/
	return 0;
}

/**** 在下面编写满足任务要求的递归函数isPalindrome，是回文返回1，不是返回0 *******/ 
/**********  Begin ***********/
int isPalindrome(char arr[],int len){
    for(int i=0;i<len/2;i++){
        if(arr[i]!=arr[len-i-1]){
            return 0;
        }
    }
    return 1;
}
/**********  End  **********/