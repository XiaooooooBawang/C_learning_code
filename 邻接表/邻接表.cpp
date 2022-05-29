#include<stdio.h>
int  book[10], dis[10];
int u[11], v[11], w[11];    //u[i]号顶点到v[i]号顶点的边是w[i]
int first[10], next[10];   //first数组的0-n-1号单元格分别用来存储1-n号顶点的第一条边的编号
int main()
{
	int n, m,  start, min,inf=999999,k,x=0;       //n是顶点个数，m是边的条数,start是起点（源点）
	scanf("%d%d", &n, &m);
	printf("起点是：");
	scanf("%d", &start);
	//初始化first数组值都为-1，表示1-n号顶点都没有边
	for (int i = 0; i < n; i++)
	{
		first[i] = -1;
	}
	//邻接表存储
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &u[i],&v[i],&w[i]);   //读入每一条边
		next[i] = first[u[i]];       
		first[u[i]] = i;
	}
	//初始化dis数组，为最原始路程
	dis[start - 1] = 0;
	for (int i = 1; i < n; i++)
	{
		dis[i] = inf;
	}
	k = first[start - 1];
	while (k != -1)
	{
		dis[v[k]] = w[k];
		k = next[k];
	}
	for (int i = 0; i < n; i++)
	{
		book[i] = 0;
	}
	book[start - 1] = 1;
	//Dijkstra核心算法
	for (int i = 0; i < n - 1; i++)
	{
		min = inf;
		for(int j=0;j<n;j++)
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				x=j;
			}
		}
		
		book[x] = 1;
		k = first[x];
		while (k != -1)
		{
			if (book[v[k]]==0&&dis[v[k]] > w[k]+dis[u[k]] )
			{
				dis[v[k]] = w[k]+dis[u[k]];
			}
			k = next[k];
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}
