/*本关任务（习题5.13）：输入整数n和k，输出n中从右端开始的第k个数字的值（k从1开始）。

将求n中右端第k个数字定义成函数digit(n,k)，如果k超过了n的位数，则函数返回-1；否则返回n中第k个数字。

例如：digit(345876,4)=5，digit(345,4)=-1*/
#include <stdio.h>
#include<math.h>
//请根据step3_main.cpp中的主函数流程，补全此函数
int digit(long n, int k)
{
	/**********  Begin  **********/
    int b=0;
    int a=0;
    int c=n;
    if(n<10&&n>=0&&k==1){
        return n;
    }
    while(c){
        c=c/10;
        b++;
    }
    if(k>b){
        return -1;
    }
    else{
        for(int i=1;i<k;i++){
            n=n/10;
        }
    }
    a=n%10;
    return a;
    /**********  End  **********/
}


#include <stdio.h>
#include "step3_stu.h"

//请根据此函数补全step3_stu.h文件中digit()函数
int main()
{
    long n;
    int k;
    scanf("%ld%d",&n,&k);
    if( n < 0)
        n = -n;
    printf("%d",digit(n,k));
    return 0;
}
