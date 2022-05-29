#include<stdio.h>
int e[10][10];
int inf = 99999999;
int main()
{
	int n,m,a,b,c;       //n是顶点个数，m是边的条数
	scanf_s("%d%d", &n,&m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i==j)
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

	//floyd-Warshall核心算法
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (e[i][j]>e[i][k]+e[k][j]&& e[i][k]<inf&& e[k][j]<inf)
				{
					e[i][j] = e[i][k] + e[k][j];
				}

			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}