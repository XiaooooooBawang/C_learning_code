#include<stdio.h>
struct note
{
	int x;
	int y;
	int s;
}queue[400];
int main()
{
	int a[20][20] = { 0 }, book[20][20] = { 0 };
	int head = 0, tail = 0;    //队列初始化
	int way[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
	int startx, starty, m, n, mapx, mapy,tx,ty;
	int flag = 0;     //用来标记是否到达终点，0为否，1为是
	scanf_s("%d%d", &mapx, &mapy);    //输入地图大小
	printf("请导入地图，0是空地，1是障碍物\n");
	for (int i = 0; i < mapx; i++)
	{
		for (int j = 0; j < mapy; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("起点坐标：\n");
	scanf_s("%d%d", &startx, &starty);
	printf("终点坐标：\n");
	scanf_s("%d%d", &m, &n);
	book[startx][starty] = 1;
	a[m][n] = 0;

	//广搜算法开始
	queue[tail].x = startx;
	queue[tail].y = starty;
	queue[tail].s = 0;
	tail++;                 //往队列中插入初始坐标
	while (head<tail)    //队列不为空时进行循环，用以拓展下一个点
	{
		for (int k = 0; k < 4; k++)     //用以列举拓展的下一个点的四个方向
		{
			tx =queue[head].x+ way[k][0];
			ty = queue[head].y+way[k][1];      //计算父级的下一个点的坐标
			if (tx<0||ty<0||tx>=mapx||ty>=mapy)
				continue;
			if (a[tx][ty]==0&&book[tx][ty]==0)
			{
				book[tx][ty] = 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				queue[tail].s = queue[head].s + 1;
				tail++;                             //发现合适的点入队
				
			}
			if (tx==m&&ty==n)
			{
				flag = 1;
				break;    //如果到达终点，跳出for循环，即不再向下一点拓展列举
			}
		}
		if (flag == 1)
			break;       //如果到达终点，跳出while循环，即不再向下一点拓展列举，这里再break是因为有for和while两个循环，要两次跳出
		head++;      //当一个点已拓展晚下一个点后，要对后面的点进行拓展
	}
	printf("最短路径是：%d", queue[tail - 1].s);
	return 0;
}