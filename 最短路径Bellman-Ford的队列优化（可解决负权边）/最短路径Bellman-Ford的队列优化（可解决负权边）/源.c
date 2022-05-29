#include<stdio.h>
int dis[10], bak[10];
int u[11], v[11], w[11];    //u[i]号顶点到v[i]号顶点的边是w[i]
int first[11], next[11],book[11];
int queue[10], head, tail;  
int main()
{
	int n, m, start, inf = 999999, flag = 0, check = 0,k;       //n是顶点个数，m是边的条数,start是起点（源点）
	scanf_s("%d%d", &n, &m);
	printf("起点是：");
	scanf_s("%d", &start);
	for (int i = 0; i < n; i++)
	{
		first[i] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &u[i], &v[i], &w[i]);   //读入每一条边
		next[i] = first[u[i] - 1];                  //邻接表存储
		first[u[i]-1]=i;
	}

	//初始化dis数组，除了自己全都是inf，才能让下面的循环有意义
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	dis[start - 1] = 0;
	head = 0;     //队列初始化
	tail = 0;
	queue[head] = start;
	tail++;
	//Bellmen-Ford核心语句
	while (head<tail)
	{
		k = first[queue[head]-1];
		while (k!=-1)
		{
			if (dis[v[k]-1]>dis[u[k]-1]+w[k])   //松弛
			{
				dis[v[k] - 1] = dis[u[k] - 1] + w[k];
				if (book[v[k]-1]==0)           //考虑加入队列
				{
					queue[tail] = v[k];
					tail++;
					book[v[k] - 1] = 1;
				}
			}
			k = next[k];
		}
		book[queue[head] - 1] = 0;     //出队
		head++;
	}
	
	for (int i = 0; i < m; i++)      //检测负权回路，若进行完全部边松弛后仍然存在此条件，则有负权回路
	{
		if (dis[v[i] - 1] > dis[u[i] - 1] + w[i])
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		printf("存在负权回路");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", dis[i]);
		}
	}
	return 0;
}