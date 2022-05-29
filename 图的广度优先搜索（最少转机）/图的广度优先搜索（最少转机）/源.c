#include<stdio.h>
int e[10][10], book[10];
struct node
{
	int cur;    //当前城市
	int sum;   //转机次数
}queue[100];
int main()
{
	int n, m,start,end,a,b,head=0,tail=0;
	int flag=0;
	scanf_s("%d%d", &n, &m);       //n是有多少个城市,m是有多少条路
	scanf_s("%d%d", &start, &end);
	for (int i = 0; i < m; i++)        //初始化领接矩阵数组
	{
		scanf_s("%d%d", &a, &b);
		e[a - 1][b - 1] = 1;
		e[b - 1][a - 1] = 1;      //此图为无向图
	}
	queue[tail].cur = start;     //起始点入队
	queue[tail].sum = 0;
	book[start] = 1;
	tail++;
	while (head<tail)
	{
		for (int k = 0; k < n; k++)
		{
			if (e[queue[head].cur][k]!=0&&book[k]==0)
			{
				book[k] = 1;
				queue[tail].cur = k;
				queue[tail].sum=queue[head].sum+1;    //只有从父级拓展成功下一点才能加一
				tail++;
			}
			if (queue[tail].cur==end)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}
	printf("最少转机%d次", queue[tail-1].sum);
	return 0;
}