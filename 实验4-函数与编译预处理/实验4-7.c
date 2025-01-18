/*实验4 程序设计第（2）题
本关任务：设计一个函数，判定形参n是否为完全数，如果是，以n的真因子之和的形式输出结果，否则，输出”n is not a perfect number“。*/
#include<stdio.h>
void isPerfect(int n)
//请完成isPerfect函数，判断整数n是否为完全数
{
/**********   Begin   **********/
    long long sum;
    sum = 0;
    for (long long i = 2; i < n; i++) {
        if (n % i == 0)
            sum += i;
    }
    sum += 1;
    if (sum == n) {
        printf("%d=1", n);
        for (long long i = 2; i < n; i++) {
            if (n % i == 0) {
                printf("+%d", i);
            }
        }
    }
    else printf("%d is not a perfect number", n);
/**********    End    **********/
}
/*#include"step3_func.h"

int main(void)
{
	int n;
   scanf("%d",&n);
   isPerfect(n);
}*/