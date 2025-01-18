//将输入的一行字符逆序输出。
//例如，输入string，则输出gnirts。将逆序输出用递归函数实现
#include<stdio.h>
  char input[80];
  int i=0;
/**
  请使用递归定义此函数，将输入的一行字符逆序输出。
  字符的输入和输出用getchar和putchar函数
 **/
void myrever(void)
{
	/**********  Begin  **********/
    char c = getchar(); // 读取一个字符
    if (c != EOF) { // 如果不是换行符或EOF，递归调用
        myrever(); // 递归调用
        putchar(c); // 递归返回后输出字符
    }

    /**********  End  **********/
}

#include<stdio.h>
#include"step5_stu.h"

//请根据此主函数流程使用递归完成step5_stu.h文件中myrever()函数

int main(void)
{
	myrever();
	return 0;
}