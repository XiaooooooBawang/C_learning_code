#include<stdio.h>
int dis[10],bak[10];
int u[11], v[11], w[11];    //u[i]号顶点到v[i]号顶点的边是w[i]
int main()
{
	int n, m, start, inf = 999999,flag=0,check=0;       //n是顶点个数，m是边的条数,start是起点（源点）
	scanf_s("%d%d", &n, &m);
	printf("起点是：");
	scanf_s("%d", &start);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &u[i], &v[i], &w[i]);   //读入每一条边
	}

	//初始化dis数组，除了自己全都是inf，才能让下面的循环有意义
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	dis[start - 1] = 0;
	//Bellmen-Ford核心语句
	for (int k = 0; k < n - 1; k++)   //松弛n-1轮
	{
		for (int j = 0; j < n; j++)   //复制dis数组到bak便于后面比较
		{
			bak[j] = dis[j];
		}
		for (int i = 0; i < m; i++)   //枚举每一条边
		{
			if (dis[v[i] - 1] > dis[u[i] - 1] + w[i])    //注意！！！dis里面用的uv数组的值要-1
			{
				dis[v[i] - 1] = dis[u[i] - 1] + w[i];
			}
		}
		for (int j = 0; j < n; j++)   
		{
			if (bak[j]!=dis[j])
			{
				check = 1;
				break;
			}
		}
		if (check==0)
		{
			break;
		}

	}
	for (int i = 0; i < m; i++)      //检测负权回路，若进行完全部边松弛后仍然存在此条件，则有负权回路
	{
		if (dis[v[i]-1]>dis[u[i]-1]+w[i])
		{
			flag = 1;
		}
	}
	if (flag==1)
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