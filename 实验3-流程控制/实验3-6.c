/*实验课本P85  程序设计第（2）题
输入一个n位数(1≤n≤4)，若n位数平方的末尾n位和原数相同，则输出该数。找出所有满足该要求的n位数。*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,square,last;
    scanf("%d",&n);
    if(n==1)
        printf("1 ");
    for(int i=pow(10,n-1)+1;i<pow(10,n);i++){
        last=(int)(i*i)%(int)pow(10,n);
        if(last==i)
            printf("%d ",i);
    }
    return 0;
}