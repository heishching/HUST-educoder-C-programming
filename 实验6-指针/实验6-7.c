/*实验教材P182 程序设计第（2）题
定义函数RemoveSame(a,n)，去掉有n个元素的有序整数序列a中的重复元素，返回去重后序列的长度。*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
int RemoveSame(int* x, int n) {
    int len_after = n, j;
    for (int i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (*(x + i - j - 1) != '\0') break;
        }
        if (*(x + i - j - 1) == *(x + i)) {
            len_after--;
            *(x + i) = '\0';
        }
    }
    return len_after;
}
int main() {
    int input[100];
    int* p;
    int length, n, m=0;
    p = input;
    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%d", p + i);
    }
    n = RemoveSame(input, length);
    for (int print_num=0; print_num < n;m++) {
        if (*(p + m) != '\0') {
            if(print_num==n-1) printf("%d", *(p + m));
            else printf("%d ", *(p + m));
            print_num++;
        }
    }
    printf("\n%d",n);
    return 0;
}