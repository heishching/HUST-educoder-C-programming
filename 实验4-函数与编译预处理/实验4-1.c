/*教材P108 跟踪调试第（1）题。
本关任务：求斐波那契级数前n项的和。
题目要求详见教材，线下完成跟踪调试任务后，提交最后一问的程序
(去掉原题中的输入提示语句)进行评测,注意题目要求，要用递归，不能用循环，否则计0分。*/
/******************  begin *********************/
#include<stdio.h>
long f[1000]={0,1,1};
int main(void){
    int i,k;
    long sum=0,fabonacci(int n);
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        sum+=fabonacci(i);
    }
    printf("%ld",sum);//attention,here is ld
    return 0;
}
long fabonacci(int n){
    if(f[n]) return f[n];
    return(f[n]=fabonacci(n-1)+fabonacci(n-2));
}
