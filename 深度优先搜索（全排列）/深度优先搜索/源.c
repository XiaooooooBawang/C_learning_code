#include<stdio.h>
int n, book[10], a[10];    /*a是“盒子”，book是“数表”*/

void dfs(int step)
{
	if (step == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", a[i]);
			if (i == n)
				printf("\n");
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (book[i]==0)
		{
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
}
int main()
{
	scanf_s("%d", &n);
	dfs(1);
	return 0;
}