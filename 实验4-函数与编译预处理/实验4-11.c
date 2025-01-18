/* 实验4 程序设计第（6）题
本关任务：一个C程序由file1.c、file2.c、file.h三个文件组成，两个源文件的内容已经给出。试编辑该多文件C程序，补充file.h头文件内容，相应修改file1.c、file2.c。平台评测时会自动将file1.c、file2.c进行编译、链接成可执行文件并运行。

提示：可依据下图提示进行文件切换，完成多文件的编辑。*/
//file.c
#include<stdio.h>
#include"file.h"//this head file are used to declare func1,x,y,ch
int x,y;
char ch;
int main()
{
	x=10;
   y=20;
   ch=getchar();
   printf("in file1 x=%d,y=%d,ch is %c\n",x,y,ch);
	func1();
	return 0;
}
//file2.c
#include<stdio.h>
#include"file.h"
void func1(void)
{
    x++;
	y++;
	ch++;
	printf("in file2 x=%d,y=%d,ch is %c\n",x,y,ch);
}
//file.h
/*****编写该头文件*****/
extern void func1(void);
extern int x,y;
extern char ch;