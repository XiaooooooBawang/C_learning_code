#include<stdio.h>
struct edge
{
	int u;
	int v;
	int w;
}e[100],t;    //t是交换变量
int f[100], n, m, count, sum;    //n是城市个数，m是边的条数
void quicksort(int left,int right)
{
	int i,j;
	i = left;
	j = right;
	if (left>=right)
	{
		return;
	}
	while (i<j)
	{
		while (e[j].w>=e[left].w&&i<j)
		{
			j--;
		}
		while (e[i].w<=e[left].w&&i<j)
		{
			i++;
		}
		if (i < j)
		{
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	quicksort(left, i - 1);
	quicksort(i + 1, right);
	return;
}
int getf(int j)
{
	if (f[j]==j)
	{
		return f[j];
	}
	else
	{
		f[j] = getf(f[j]);
		return f[j];
	}
}
int merge(int x,int y)
{
	int t1, t2;
	t1 = getf(x);
	t2 = getf(y);
	if (t1!=t2)
	{
		f[t2] = t1;
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	quicksort(0,m-1);
	for (int i = 1	; i <= n; i++)
	{
		f[i] = i;
	}
	//kruskal核心语句
	for (int i = 0; i < m; i++)   //从小到大枚举每一条边
	{
		if (merge(e[i].u,e[i].v))
		{
			count++;
			sum += e[i].w;
		}
		if (count==n-1)
		{
			break;
		}
	}
	printf("%d", sum);
	return 0;
}