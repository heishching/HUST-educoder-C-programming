/*利用文件操作重写实验六程序设计第(4)题。原始矩阵数据存放在当前目录下的文本文件matrix.in中，
文件的第一行是两个整数n和m，表示矩阵的行数n和列数m，接下来的n行，每行有m个整数，表示矩阵数据。
要求从matrix.in读数据，旋转后的矩阵输出到当前目录下的文本文件matrix.out中，该文件有m行，每行有n个整数。
   你不需要输出matrix.out中的内容，由平台输出。*/
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
    int n,m;
    FILE *f;
    char file[100];
    scanf("%s",file);
    f=fopen(file,"r");
    fscanf(f,"%d %d", &n, &m);
    int input[n][m];
    int output[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f,"%d", &input[i][j]);
        }
    }
    fclose(f);
    f=fopen("matrix.out","w");
    turn(n,m,input, output);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(j!=n-1 ) fprintf(f,"%d ", output[i][j]);
            else fprintf(f,"%d\n", output[i][j]);
        }
    }
    return 0;
}