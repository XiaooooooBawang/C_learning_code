#include<stdio.h>
int e[10][10], book[10] , dis[10];
int inf = 99999999;
int main()
{
	int n, m, a, b, c,start,min,u=0;       //n是顶点个数，m是边的条数,start是起点（源点）
	scanf_s("%d%d", &n, &m);
	printf("起点是：");
	scanf_s("%d", &start);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = inf;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &a, &b, &c);
		e[a - 1][b - 1] = c;
	}
	//初始化dis数组，为最原始路程
	for (int i = 0; i < n; i++)
	{
		dis[i] = e[start-1][i];
	}
	for (int i = 0; i < 10; i++)
	{
		book[i] = 0;
	}
	book[start-1] = 1;
	//Dijkstra核心算法
	for (int i = 0; i < n - 1; i++)
	{
		min = inf;
		for (int j = 0; j < n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (int v = 0; v < n; v++)
		{
			if (e[u][v]<inf)
			{
				if (dis[v] > dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}