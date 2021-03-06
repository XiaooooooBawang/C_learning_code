#include<stdio.h>
int n, m;   
int e[1000][1000];       //a二维矩阵存储边
int dis[1000][1000];    //dis存储两村庄之间修一间小学，各村庄到学校距离之和最小值
int v[1000][1000];      //存储最优解,v[i][j]表示在前i个村庄中建j所小学的最优解
int i, j, k,inf=999999;
int main()
{
	scanf_s("%d%d", &n, &m);   //n是村庄数 ，m是小学数
	for ( i = 1; i < n; i++)
	{
		scanf_s("%d", &e[i][i + 1]);
	}
	for ( i = 1; i <= n; i++)
	{
		for ( j = i+1; j <=n; j++)
		{
			e[i][j] = e[i][j - 1] + e[j - 1][j];
			e[j][i] = e[i][j];                     //要建双向表，下面①处会有k>中点
		}
	}
	for ( i = 1	; i <n; i++)
	{
		for ( j = 2; j <= n; j++)
		{
			for ( k = i; k <= j; k++)
			{
				dis[i][j] += e[k][(i + j) / 2];     //①学校建在中点可使其最小
			}
		}
	}
	for ( i = 1; i <= n; i++)
	{
		v[i][1] = dis[1][i];
	}
	for ( i = 1; i <= n; i++)       //填表
	{
		for ( j = 2; j <= m; j++)
		{
			v[i][j] = inf;
			for ( k =j-1 ; k <= i; k++)    //k要比j-1（要建的学校）大，比i（取的村庄）小
			{
				v[i][j] = (v[k][j - 1] + dis[k + 1][i])<v[i][j]? (v[k][j - 1] + dis[k + 1][i]): v[i][j];
				/*
				v[k][j - 1]是前k个村庄中建j - 1所学校的已确定的最优解，dis[k + 1][i]是k + 1到i村庄中建1所学校
				的距离最小值，k相当于是把i个村庄分成两半，把问题分成取前k个村庄建j-1所学校和后面的村只建1所学校
				两个子问题，动态更新取前i个村建j所学校的最优解即v[i][j]，填完表后输出即可
				*/
			}
		}
	}
	printf("%d", v[n][m]);
	return 0;
}