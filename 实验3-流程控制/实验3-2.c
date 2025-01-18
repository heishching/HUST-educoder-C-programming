/*实验教材P85 程序修改替换第（1）题
修改第一关的代码，将内层两出口的for循环结构改用单出口结构，即不允许用break，goto等非结构化语句*/
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
			}
    if (flag==0)
    printf("%d不是合数",x);
	return 0;
}