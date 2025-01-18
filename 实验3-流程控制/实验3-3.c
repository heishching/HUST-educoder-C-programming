/*实验教材P85 程序修改替换第（2）题
修改第一关的代码，将for循环改用do-while循环*/
#include<stdio.h>
#include<math.h>
int main()
{
	int i,x,k,flag;
    flag=0;
//	printf("本程序判断合数，请输入大于1的整数，以Ctrl+Z结束\n");
	scanf("%d",&x);
     if(x==1)
        printf("1不是合数");
    if(x==2)
        printf("2不是合数");
    i=2;
    do{
        if(x%i==0){
		printf("%d是合数",x);
        flag=1;}
        i++;
    }
    while(i*i<=x);
    if (flag==0)
    printf("%d不是合数",x);
	return 0;
}