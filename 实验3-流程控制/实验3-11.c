/*实验课本P86  程序设计第（10）题
用筛法构造素数表，输入m(4≤m≤1000000)，查表找出m之前的所有孪生素数。*/
#include<stdio.h>
int main()
{
    int m;
    scanf("%d",&m);
    int num[m+1];
    for(int c=0;c<=m+1;c++) num[c]=1;
    num[1]=0;//num[prime number]=1
    for(int i=1;i*i<=m;i++){
        if (num[i]==1){//i is prime,ni isn't prime
            for(int j=2;i*j<=m;j++)
                num[i*j]=0;
        }
    }
    for(int k=3;k<=m-2;k++){
        if(num[k]==1&&num[k+2]==1)
            printf("(%d,%d) ",k,k+2);
    }
    return 0;
}