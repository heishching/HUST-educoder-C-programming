/*实验课本P85  程序设计第（3）题
输入一直股票连续n天的收盘价格，输出该股票这n天中的最大波动值，波动值是指某天收盘价格与前一天收盘价格只差的绝对值。*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n, wave;
    wave = 0;
    scanf("%d", &n);
    int price[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    for (int j = 1; j < n; j++) {
        wave = abs(price[j] - price[j - 1]) > wave ? abs(price[j] - price[j - 1]) : wave;
    }
    printf("%d", wave);
    return 0;
}