/*本关任务：完善实验指导书P142的求解约瑟夫问题的源程序：M个人围成一圈，从第一个人开始一次从1至N报数，每当报数为N时报数人出圈，直到圈中只剩下一个人为止。

本任务改为键盘输入 M 和 N 。*/
# include<stdio.h>

int main(void)
{
    int M,N;
    scanf("%d %d",&M,&N);
    int a[M], b[M];
    int i, j, k;
        for (i = 0; i < M; i++)
        a[i] = i + 1;//STASTIC
    for (i = M, j = 0; i > 1; i--)//stop when only one was left
    {
        for (k = 1; k <= N; k++) {//count the number
            while (1) { 
                j++;
                if (a[j - 1] != 0) break;
            }
           if (j > M) j = 0;//如果下一个顺序大于人数，则从0计数；j代表实际中的序号
        }
        if(j!=0) a[j - 1] =0;
    }
    for (int c = 0; c < M; c++)
        if (a[c] != 0) {
            printf("%6d", a[0]);
            break;
        }
    return 0;
}