/*实验指导书 P144 程序设计第（11）题
本关任务：迷宫问题。编程找出从入口（左上角方格）经过迷宫到达出口（右下角方格）的所有路径，迷宫问题示意如下方数字阵列所示，0所表示的地方是不可以通行的，只能从1走到与它相邻（四邻域：上、下、左、右相邻）的1上，且不能走重复路径。
迷宫问题示意图：
1 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 1 1 1 0
1 1 1 0 0 1 1 0 1 0
1 0 0 1 1 1 0 0 1 0
1 1 1 1 0 1 1 1 1 0
0 0 0 0 0 0 0 0 1 1

本任务由键盘输入迷宫的行数和列数，以及迷宫的图案。*/
#include<stdio.h>
#include<stdlib.h>

int m,n;

void dps(int x, int y, int map[m + 2][n + 2], int desx, int desy, int visited[m + 2][n + 2]);

int cnt = 0;

int main()
{
    
    scanf("%d%d",&m,&n);
	int map[m + 2][n + 2] ;
	int visited[m + 2][n + 2] ;//加2是要把四周也设成零当围墙
    for(int i=0;i<=m+1;i++)
		for (int j = 0; j <= n+1; j++)
            map[i][j]=0;
    for(int i=0;i<=m+1;i++)
        for (int j = 0; j <= n+1; j++)
            visited[i][j]=0;
//初始化
	for(int i=1;i<=m;i++)
		for (int j = 1; j <= n; j++) 
			scanf("%d", &map[i][j]);//输入
    visited[1][1]=1;    
	dps(1, 1, map, m, n, visited);
	return 0;
}

void dps(int x, int y, int map[m + 2][n + 2], int desx,int desy,int visited[m + 2][n + 2])
{
	//printf("(% d, % d)\t", x, y);
	if (x == desx && y == desy) {//desx与desy是终点坐标
		printf("%d\n", ++cnt);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j < n; j++)
				printf("%d ", visited[i][j]);//visited中存储了走过的点，就可以打印
                printf("%d\n",visited[i][n]);
		}
		return;
	}//输出
	if (map[x + 1][y] == 1 && visited[x + 1][y] == 0) {
		visited[x + 1][y] = 1;
		dps(x + 1, y, map, desx, desy, visited);//先继续找，找完了把这个visit状态取消掉，也就是退回上一级继续找
		visited[x + 1][y] = 0;
	}
	if (map[x][y + 1] == 1 && visited[x][y + 1] == 0) {
		visited[x][y + 1] = 1;
		dps(x, y + 1, map, desx, desy, visited);
		visited[x][y + 1] = 0;
	}
	if (map[x - 1][y] == 1 && visited[x - 1][y] == 0) {
		visited[x - 1][y] = 1;
		dps(x - 1, y, map, desx, desy, visited);
		visited[x - 1][y] = 0;
	}
	if (map[x][y - 1] == 1 && visited[x][y - 1] == 0) {
		visited[x][y - 1] = 1;
		dps(x , y - 1, map, desx, desy, visited);
		visited[x][y - 1] = 0;//按照一定的顺序挨个检索
	}
	visited[x][y] = 0;//最后如果都没有，就再退回
	return;
}
