/*实验课本P86  程序设计第（6）题
梅森数是形如2n-1的正整数，其中指数n是素数，记为M(n)。如果一个梅森数是素数，则称为梅森素数。例如，M(2)=22-1=3是梅森素数，而M(11)=211-1=2047=23×89不是梅森素数。
输入一个大于3的长整数m，输出不大于m的所有梅森素数。*/
#include<stdio.h>
#include<math.h>
int isprime(int x){
    if (x==1) return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
    long m,meissen;
    scanf("%d",&m);
    for(int n=1;meissen=pow(2,n)-1,meissen<=m;n++){
        if(isprime(meissen)) printf("M(%d)=%d\n",n,meissen);
    }
    return 0;
}