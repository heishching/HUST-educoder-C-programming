/*实验指导书P142 约瑟夫问题第（2）问
本关任务：改进实验指导书P142的求解约瑟夫问题的源程序，采用标记元素而非压缩数组的方法记录出圈者。*/
# include<stdio.h>

int main(void)
{
    int M,N;
    scanf("%d %d",&M,&N);
    int a[M];
    int i, j, k,record;//last =the last person who count the num
    record=0;
    for (i = 0; i < M; i++)
        a[i] = i + 1;//STASTIC
    for (i = M, j = 0; i > 1; i--)//stop when only one was left
    {
        for (k = 1; k <= N; k++) {//找报N的人
            while (1) { //while 找谁报数
                j++;
                if (j > M) j = 1;//如果下一个顺序大于人数，则从0计数；j代表实际中的序号
                if (a[j - 1] != 0) break;
            }
            if (k == N - 1) record = j;
        }
        a[j - 1] = 0;
    }
    printf("% d", a[record-1]);
    return 0;
}