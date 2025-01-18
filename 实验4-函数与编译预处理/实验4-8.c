/*实验课本 实验4 程序设计第（4）题
本关任务：用带参数的宏计算三角形面积。

相关知识
三角形面积area=(s(s-a)(s-b)(s-c))^0.5,其中s=(a+b+c)/2*/
/***定义两个带参数的宏,用于计算三角形面积***/
#include<stdio.h>
#include<math.h>
#define s(a,b,c) ((a+b+c)/2)
#define area(s,a,b,c) (sqrt(s*(s-a)*(s-b)*(s-c)))
int main(void)
{
    int a,b,c,p;
    scanf("%d %d %d",&a,&b,&c);
    p=s(a,b,c);
    printf("%.2f",area(p,a,b,c));
    return 0;
}