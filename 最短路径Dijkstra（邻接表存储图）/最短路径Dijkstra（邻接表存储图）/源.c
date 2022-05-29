#include<stdio.h>   //注意！！！！下面用到的数组都是从第0格开始存储数据，而uv数组各自的值代表的是实际顶点的值，所以用到uv数组复合其他数组的时候uv数组值要-1，但next不用管-1
int  book[100], dis[100];
int u[11], v[11], w[11];    //u[i]号顶点到v[i]号顶点的边是w[i]
int first[100], next[100];   //first数组的0-n-1号单元格分别用来存储1-n号顶点的第一条边的编号
int main()
{
	int n, m,  start, min,inf=999999,k,x=0;       //n是顶点个数，m是边的条数,start是起点（源点）
	scanf_s("%d%d", &n, &m);
	printf("起点是：");
	scanf_s("%d", &start);
	//初始化first数组值都为-1，表示1-n号顶点都没有边
	for (int i = 0; i < n; i++)
	{
		first[i] = -1;
	}
	//邻接表存储
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &u[i],&v[i],&w[i]);   //读入每一条边
		next[i] = first[u[i]-1];       
		first[u[i]-1] = i;
	}
	//初始化dis数组，为最原始路程
	for (int i = 0; i < n; i++)
	{
		dis[i] = inf;
	}
	dis[start - 1] = 0;

	k = first[start - 1];
	while (k != -1)
	{
		dis[v[k]-1] = w[k];
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
		k = first[start - 1];            //在不断寻找离源点的依次最近点时，不要用邻接表搜索，因为离源点的最近值是不断在dis中更新的，但邻接表是不会变的
		min = inf;
		while (k!=-1)
		{
			if (book[v[k]-1]==0&&dis[v[k]-1]<min)
			{
				min = dis[v[k] - 1];
				x = v[k]-1;
			}
			k = next[k];
		}
		/*min = inf;
		for (int j = 0; j < n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				x = j;
			}
		}*/
		book[x] = 1;
		k = first[x];             //这里能用搜索邻接表是因为我们要通过上面找到的依次最近点实现松弛，那必须是那个点有出边才可以进行
		while (k != -1)
		{
			if (book[v[k]-1]==0&&dis[v[k]-1] > w[k]+dis[u[k]-1] )
			{
				dis[v[k]-1] = w[k]+dis[u[k]-1];
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