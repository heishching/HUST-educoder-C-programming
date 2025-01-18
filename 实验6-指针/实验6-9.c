/*实验指导书 P182 程序设计第（6）题

本关任务：命令行实现对N个整数排序。*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sortup(int input[], int n);
void sortdown(int input[], int n);
int main(int argc, char* argv[]) {
    //int n=argv[1]-'0';//注意，argv是二维数组，argv[1]是指针
    int n = 0;
    n=atoi(argv[1]);
    int input[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    //if(argc==2||argv[2][1]!="-") sortdown(input,n);错的，argv[2][1]是字符，-是字符串
    if (argc == 2 || strcmp(argv[2], "-d") != 0) sortup(input, n);
    else sortdown(input, n);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) printf("%d", input[i]);
        else printf("%d ", input[i]);
    }
}
void sortup(int input[], int n) {
    int t;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (input[j] < input[j - 1]) {
                t = input[j];
                input[j] = input[j - 1];
                input[j - 1] = t;
            }
        }
    }
}
void sortdown(int input[], int n) {
    int t;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (input[j] > input[j - 1]) {
                t = input[j];
                input[j] = input[j - 1];
                input[j - 1] = t;
            }
        }
    }
}