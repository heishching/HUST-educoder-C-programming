/*程序填空，写一个表达式，如果整数a能被3整除且个位数字为5，则结果为1，否则结果为0。
在右侧编辑器Begin-End处写出符合任务要求的表达式*/
 /**********使用unsigned int变量a，在下面写出满足任务要求的表达式**********/
 /**********Begin**********/
  (a%3==0)&&(a%10==5)?1:0  
 /**********End**********/
 #include <stdio.h>

int main() {
	int a, flag;
	scanf("%d", &a);
	flag =(
    #include "step5_stu.h"
    );
	printf("%d", flag);
	return 0;
}