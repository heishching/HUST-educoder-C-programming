/*实验课本 实验4 程序设计第（1）题
本关任务：设计一个函数对其形参验证歌德巴赫猜想，并以“n=n1+n2”的形式输出结果。

相关知识
哥德巴赫猜想：一个大于等于4的偶数可以表示成两个素数之和*/
#include<stdio.h>
void goldbach(int n)
//请完成goldbach函数，将大于等于4的偶数n表示成两个素数的和。
{
/**********   Begin   **********/
int i,j,state;
j=0;
state=0;
for(i=2;i<=n/2;i++){
    j=n-i;
    //judge whether i is a prime num
    for(int a=2;a*a<=i;a++){
        if(i%a==0){
        state=1;
        break;
        }
    }
    //judge whether j is a prime num
    for(int b=2;b*b<=j;b++){
        if(j%b==0){
        state=1;
        break;
        }
    }
    if(state==0){//state=0 means that both a&b are prime num
        printf("%d=%d+%d",n,i,j);
        break;
    }
    state=0;
}


/**********    End    **********/
}
/*
#include<stdio.h>
#include"step2_func.h"

int main(void)
{
	int n;
   scanf("%d",&n);
   goldbach(n);
   return 0;
}*/