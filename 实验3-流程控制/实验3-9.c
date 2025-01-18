/*实验课本P85  程序设计第（5）题
编写一个能打印n行杨辉三角的小程序。*/
#include<stdio.h>
int combinatorial(int n, int k) {
    int njc, kjc, nkjc;
    njc = 1;
    kjc = 1;
    nkjc = 1;
    if (n == 0) njc = 1;
    else {
        for (int a = 1; a <= n; a++) {
            njc = njc * a;
        }
    }
    if (k == 0) kjc = 1;
    else {
        for (int b = 1; b <= k; b++) {
            kjc = kjc * b;
        }
    }
    if (n == k) nkjc = 1;
    else {
        for (int c = 1; c <= (n - k); c++) {
            nkjc = nkjc * c;
        }
    }
    return (njc / (kjc * nkjc));
}
int main()
{
    int n, yang, last;
    scanf("%d", &n);
    if (n == 0)
        printf("1");
    else {
        for (int i = 0; i <= n; i++) {
            for (int space = 1; space <= 2 * n - 2 * i; space++)
                printf(" ");
            for (int j = 1; j <= i + 1; j++) {
                yang = combinatorial(i, j - 1);
                printf("%d", yang);
    //            if (j != i + 1) {
                    if (yang < 10) printf("   ");
                    else if (yang < 100) printf("  ");
                    else if (yang < 1000) printf(" ");
          //      }
            }
            printf("\n");
        }
    }
    return 0;
}