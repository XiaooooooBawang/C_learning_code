#include<stdio.h>
int e[10][10],book[10];
int m, n, a, b, c,min=999999;

void dfs(int cur,int dis)     //cur是当前城市
{
	if (dis > min)        //如果当前已走路程已经大于之前找到的最短路，没必要往下走，直接返回，节省时间
		return;
	if (cur==n-1)          //判断是否到达目标
	{
		if (dis < min)
			min = dis;     //到达目标后查看当前路程，判断是否能更新最小值
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (e[cur][j]!=0&&e[cur][j]!=999999&&book[j]==0)
		{
			book[j] = 1;
			dfs(j,dis+e[cur][j]);
			book[j] = 0;
		}
	}
	return;
};
int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < n; i++)             //先初始化领接矩阵数组，后面再输入覆盖
	{
		for (int j = 0; j < n; j++)
		{
			if (i==j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 999999;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &a, &b, &c);
		e[a - 1][b - 1] = c;
	}
	book[0] = 1;    //标记1号（0）城市已走
	dfs(0,0);     //第一步是1号（0）城市
	printf("最短路径是%d",min);
}