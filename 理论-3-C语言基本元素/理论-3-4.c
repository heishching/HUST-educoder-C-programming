/*代码填空，写一个表达式，求整数a，b，c三个数中最大值。
根据提示，在右侧编辑器Begin-End填写表达式，表达式的值等于三个数中的最大值。*/
 /**********使用int变量a, b, c，在下面写出满足任务要求的表达式**********/
 /**********Begin**********/
 (b>a?b:a)>c?(b>a?b:a):c   
 /**********End**********/
 #include <stdio.h>

int main() {
	int a, b, c, max;
	scanf("%d%d%d", &a, &b, &c);
	max =( 
    #include "step4_stu.h"
    );
	printf("%d", max);
	return 0;
}