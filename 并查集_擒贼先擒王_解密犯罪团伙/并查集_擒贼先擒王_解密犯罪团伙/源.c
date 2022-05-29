#include<stdio.h>
int f[100];       //数组下标表示强盗编号，数组值表示下标强盗的老板
int getf(int v)    //找爹的递归函数
{
	if (f[v] == v)
		return f[v];
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}
}
void merge(int u,int w)
{
	int t1, t2;
	t1 = getf(u);
	t2 = getf(w);
	if (t1!=t2)
	{
		f[t2] = t1;    //靠左原则
	}
}
int main()
{
	int n, m,x,y,sum=0;         //n是人数，m是线索条数
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)      //初始化f，自己就是自己老板
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i]==i)
		{
			sum++;
		}
	}
	printf("%d", sum);
}