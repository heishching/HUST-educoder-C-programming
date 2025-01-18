/*实验指导书 P139~140 程序改错与跟踪调试题，请按书中的步骤调试程序，找出函数strncate(t,s)和strdelc(s,c)中的错误并改正。

本任务改用在main函数中输入串a、串b以及待删除字符。

*/
#define _CRT_SECURE_NO_WARNINGS
//
#include<stdio.h>
void strcate(char[], char[]);
void strdelc(char[], char);
int main(void) {
    char a[100], b[100];
    char del;
    scanf(" %[^\n]", a);
    scanf(" %[^\n]", b);
    scanf(" %c", &del);
    strcate(a, b);
    printf("%s\n", a);
    strdelc(a, del);
    printf("%s\n", a);
    return 0;
}
void strcate(char t[], char s[]) {
    int i = 0, j = 0;
    while (t[i]) {
        i++;
    } // 找到t的末尾
    while (s[j] != '\0') {
        t[i++] = s[j++];
    } // 将s连接到t的末尾
    t[i] = '\0';
}

void strdelc(char s[], char c) {
    int j = 0, k = 0;
    for (; s[j] != '\0'; j++) {
        if (s[j] != c) {
            s[k++] = s[j];
        }
    }
    s[k] = '\0'; // 确保字符串以空字符结尾
}
