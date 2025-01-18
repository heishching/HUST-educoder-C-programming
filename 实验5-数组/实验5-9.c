/*实验指导书 P143 程序设计第（5）题
本关任务：编写函数strnins(t,s,n),其功能是：将串s插入串t串的第n个字符的后面，编写main函数测试strnins函数的正确性。*/
#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
#include<string.h>

void strnins(char t[], char s[], int n) {
    int lengths = strlen(s);
    int lengtht = strlen(t);
    for (int i = lengtht - 1; i > n - 1; i--) {
        t[i + lengths] = t[i];
    }
    for (int i = 0; i < lengths; i++) {
        t[n + i] = s[i];
    }
    t[lengths + lengtht ] = '\0';
}
int main() {
    char s[100];
    char t[100];
    int n;
    scanf("%s", t);
    scanf("%s", s);
    scanf("%d", &n);
    strnins(t, s, n);
    printf("%s", t);
    return 0;
}