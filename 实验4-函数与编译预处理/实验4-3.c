/*教材P106，程序改错第（1）题
本关任务：右侧是计算s=1!+2!+3!+...+n!的程序。程序中存在若干语法和逻辑错误，要求对程序进行修改，使其能够输出正确结果。*/
#include<stdio.h>
long long sum_fac(int n);
int main(void)
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %ld\n",k,sum_fac(k));
	return 0;
}
long long sum_fac(int n){
	long long s=0,fac=1;//s is sum
	int i;//fac =n!
	for(i=1;i<=n;i++) {
    fac*=i;
	s+=fac;
    }
	return s;
}
