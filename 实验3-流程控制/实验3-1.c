/*实验教材 3.3.2节 1.程序改错
认真阅读教材 P84 的任务要求，本题是程序改错题，在原代码中存在若干语法和逻辑错误，
先在本地编译和调试程序，根据观察结果，分析代码并修改程序，使之能正确完成合数判断功能。然后提交平台测试*/
#include<stdio.h>
#include<math.h>
int main()
{
	int x,k,flag;
    flag=0;
//	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
	scanf("%d",&x);
        if(x==1)
            printf("1不是合数");
        if(x==2)
            printf("2不是合数");
		for(int i=2;i*i<=x;i++)
			if(x%i==0){
				printf("%d是合数",x);
                flag=1;
				break;
			}
    if (flag==0)
    printf("%d不是合数",x);
	return 0;
}