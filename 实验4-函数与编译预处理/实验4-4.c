/*实验课本 P107 程序修改替换第（1）题
本关任务：将程序改错(1)中的sum_fac函数修改为一个递归函数，用递归的方式计算s=1!+2!+3!+...+n!*/
#include<stdio.h>
long long sum_fac(int n);
int main(void)
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %ld\n",k,sum_fac(k));
	return 0;
}
long long sum_fac(int n)
{
	long long j;
    j=1;
    if(n==1) return 1;
    else {
        for(int i=1;i<=n;i++){
            j*=i;
        }
        return j+sum_fac(n-1);
    }
}


