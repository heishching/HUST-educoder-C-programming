/*程序填空，写一个表达式，将short类型整数k的高字节作为结果的低字节，将short类型整数p的低字节作为结果的高字节，拼成一个新short类型整数。例如：
输入k的值：  -32768（对应二进制为10000000 00000000）；
输入p的值： 128      （对应二进制为00000000 10000000）；
表达式的值：-32640 （对应二进制为10000000 10000000）
根据提示，在右侧编辑器Begin-End中，使用变量k和p写出一个表达式，表达式的值满足任务要求。*/
 /********** 使用short变量k和p，在下面写出满足任务要求的表达式**********/
 /**********Begin**********/
   (short)(((unsigned short)k>>8)|((unsigned short)p<<8))
 /**********End**********/
 #include <stdio.h>
int main(int argc, char *argv[]) {
	short k, p, result;
	scanf("%hd%hd", &k, &p);
	result = (
    #include "step1_stu.h"
    );
	printf("%hd", result);  
	return 0;
}