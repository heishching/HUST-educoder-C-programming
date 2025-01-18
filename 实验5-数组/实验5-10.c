/*本关任务：消除类游戏是一种益智游戏，其核心规则是将一定的彼此相邻的相同元素配对消除。
现给定一个n行m列的棋盘，棋盘中的每一个方格上放着一个棋子，每个棋子都有颜色，编号用1~9表示。当一行或一列上有连续3个或3个以上同色棋子时，
这些棋子都被同时消除，对应的方格用0表示，请输出经过消除后的棋盘。例如，给定棋盘为：*/
# include <stdio.h>
# include <string.h>
int main() {
    int n,m,equal = 0;
    scanf("%d %d",&n,&m);
    int board[n][m];//在C语言中，不允许在声明时初始化变长数组。可以用循环，或使用memset函数(注意使用string.h头文件) Note educoder use Linux system, so you may face unexplainable problems when your program is related to RAM
    int boarda[n][m];
    int boardb[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            boarda[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            boardb[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (boarda[i][j] == boarda[i][j - 1]) {
                equal++;
                if (j == m - 1 && equal >= 2) {
                    for (int c = m - 1; c >= m - 1 - equal; c--)
                        boarda[i][c] = 0;
                }
            }
            else {
                if (equal >= 2) {
                    for (int c = j - 1; c >= j - equal - 2; c--) {
                        boarda[i][c] = 0;
                    }
                }
                equal = 0;
            }
        }
        equal = 0;
    }
    equal = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (boardb[i][j] == boardb[i - 1][j]) {
                equal++;
                if (i == n - 1 && equal >= 2) {
                    for (int c = n - 1; c >= n - 1 - equal; c--)
                        boardb[c][j] = 0;
                }
            }
            else {
                if (equal >= 2) {
                    for (int c = i - 1; c >= i - equal - 2; c--) {
                        boardb[c][j] = 0;
                    }
                }
                equal = 0;
            }
        }
        equal = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (boarda[i][j] == 0 || boardb[i][j] == 0) {
                board[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(j!=m-1) printf("%d ", board[i][j]);
            else printf("%d", board[i][j]);
        }
        printf("\n");
    }
}
/*NOTE This program remove number in line(boarda) or column(boardb) separately, 
then if a number was removed in more than one situation, it should be removed is the last result. 
It is designed to solve the problem appear when two continous equal number line have a intersection point.*/