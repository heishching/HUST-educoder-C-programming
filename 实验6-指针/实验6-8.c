/*实验指导书P182 程序设计第（4）题

输入图像矩阵的行数n和列数m，接下来的n行每行输入m个整数，表示输入的图像，输出原始矩阵逆时针旋转90°后的矩阵。*/
#include<stdio.h>
#include<stdlib.h>
void turn(int n, int m,int input[n][m], int output[m][n]) {//输入n行m列
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            output[i][j]=input[j][m-1-i];
        }
    }
}
int main() {
    int m, n;//n行m列
    scanf("%d %d", &n, &m);
    int input[n][m];
    int output[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &input[i][j]);
        }
    }
    turn(n,m,input, output);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(j!=n-1 ) printf("%d ", output[i][j]);
            else printf("%d", output[i][j]);
        }
        putchar('\n');
    }
    return 0;
}