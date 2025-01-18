/*实验指导书P183 程序设计第（10）题

本关任务：求两个不超过200位的非负整数积。
（本题涉及高精度计算，可参考理论课教材例8.9 和 实验课教材 例6.17）*/
#include<stdio.h>
#include<ctype.h>
#define N 200
void getbignum(int* x, int lim) {
    int i, t, c;
    int* p1, * p2;
    for (i = 1; i <= lim; i++) *(x + i) = 0;//清零
    for (i = 1; i <= lim && isdigit(c = getchar()); i++) {
        *(x + i) = c - '0';//先输入的高位在x[1]
    }
    *x = i - 1;//保存总位数
    for (p1 = x + 1, p2 = x + i - 1; p1 < p2; p1++, p2--) {//反转，低位在前
        t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
}
void printbignum(int* x) {
    int* p;
    int n = *x;//总位数
    for (p = x + n; p > x; p--) printf("%d", *p);//从后往前输出
}
void multiplebignum(int* x, int* y, int* z) {
    int carry = 0;//进位
    int multi = 0, i, j;
    for (i = 0; i < *x; i++) {//x
        for (j = 0; j < *y; j++) {//y
            /*
            multi = (*(x + i + 1)) * (*(y + j + 1));
            *(z + 1 + i + j) += (multi % 10 + carry) % 10;
            carry = (multi + carry) / 10;
            这样写是错的，没有考虑*(z + 1 + i + j) += (multi % 10 + carry) % 10后仍需进位的情况
            */
            multi = ((*(x + i + 1)) * (*(y + j + 1))) + (*(z + 1 + i + j)) + carry;
            *(z + 1 + i + j) = multi % 10;
            carry = multi / 10;
        }
        *(z + 1 + i + j ) += carry;//for结束后j已经加了1
        *z = carry == 0 ? i + j : i + j + 1;
        carry= 0;
    }  
}

int main() {
    int x[N + 1], y[N + 1], z[(N + 1) * 2 + 1], i;//结果最多为(10^201-1)^2,即小于10^402，
    for (i = 0; i <= N; i++) z[i] = 0;
    getbignum(x, N);
    getbignum(y, N);
    multiplebignum(x, y, z);
    printbignum(z);
    return 0;
}