/*实验指导书 P144 程序设计第（10）题
本关任务：将1、2、3、…、n^2从左上角开始，由外层至中心按顺时针方向螺旋排列所形成的数字方阵，成为n阶顺转方阵，5阶顺转方阵如下方数字阵列所示。编写程序，读入n，构造并输出n阶顺转方阵。
5阶顺转方阵：
1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出时不需严格对齐，行中以单个空格分隔、每n个数换行即可：
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9*/
# include <stdio.h>
int main(){
    int n,m=1,j,put=1,line=0,column=0;
    scanf("%d",&n);
    int table[n][n];
        for (int i = 1; i <= 2 * n - 1; i++) {
        j = (i == 1) ? n : n - i / 2;//j stands for how many numbers should be print in a line
        for (int m = 0; m < j; m++) {
            if (!(m == 0&&i==1)) {
                if (i % 2) {
                    if (i % 4 == 1)column++;
                    else column--;
                }
                else {
                    if (i % 4) line++;
                    else line--;
                }
            }
            table[line][column] = put;
            put++;
        }
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (b==n-1) printf("%d", table[a][b]);
            else printf("%d ", table[a][b]);
        }
        printf("\n");
    }
}