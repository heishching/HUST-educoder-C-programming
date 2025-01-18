/*实验教材P85 程序修改替换第（3）题
编写一个能求出所有n(2=<n=<4)位数纯粹合数的小程序。
相关知识
一个合数去掉最低位，剩下的数还是合数；再去掉剩下的数的最低位，余留下来的数还是合数，
这样反复，一直到最后剩下的一位数仍是合数，这样的数称为纯粹合数。*/
#include<stdio.h>
#include<math.h>
//function:judge whether a number is composite number
//enter:int
//output:is composite number--1;not--0
int isComposite(int x) {
    if (x == 1)
        return 0;
    if (x == 2)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, temporary, tablet;
    tablet = 1;//tablet 默认是1，即认为满足纯粹，发现不满足后=0
    scanf("%d", &n);
    for (int i = ((int)pow(10, n - 1)) + 1; i < pow(10, n); i++) {
        tablet = 1;
        if (isComposite(i)) {
            temporary = i;
            for (int j = 1; j < n; j++) {
                if (temporary % 10 != 0)
                    temporary = (temporary - temporary % 10) / 10;
                else
                    temporary = temporary / 10;
                if (!(isComposite(temporary))) {
                    tablet = 0;
                    break;
                }
            }
                if (tablet == 1)
                    printf("%d ", i);
        }
    }
    return 0;
}