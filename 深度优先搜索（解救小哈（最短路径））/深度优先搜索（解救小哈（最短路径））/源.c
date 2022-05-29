#include<stdio.h>
int  m,n,startx,starty,mapx,mapy,min=99999;   /*(m,n)是目标的坐标，(startx,starty)是起点坐标,mapx和mapy是导入地图的边界*/
int a[50][50],book[50][50];  /*a是地图数组，book是”数表“*/
int way[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };   /*方向数组，右下左上顺时针顺序*/
void dfs(int x,int y,int step)
{
	int tx, ty;
	if (x==m&&y==n)
	{
		if (min > step)
			min = step;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		tx = x + way[i][0];
		ty = y + way[i][1];
		if (tx<0||ty<0||tx>=mapx||ty>=mapy)
			continue;
		if (a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}
int main()
{
	scanf_s("%d%d", &mapx, &mapy);
	printf("请导入地图，0是空地，1是障碍物\n");
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("起点坐标：\n");
	scanf_s("%d%d",&startx,&starty );
	printf("终点坐标：\n");
	scanf_s("%d%d", &m, &n);
	book[startx][starty] = 1;
	a[m][n] = 0;
	dfs(startx, starty, 0);
	printf("最少步数是%d", min);
	return 0;
}