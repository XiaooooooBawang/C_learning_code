#include<stdio.h>
int a[15], n, max;
void dfs(int cur,int j,int sum)
{
	if (j == n)
	{
		if (sum>max)
			max = sum;
		return;
	}
	for (int k = 0; k < 2; k++)    //k=0Îª×ó£¬k=1ÎªÓÒ
	{
		dfs(cur + j + k, j+1, sum += a[cur + j + k]);
		sum -= a[cur + j + k];
	}
	return;
}
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < 15; i++)
	{
		scanf_s("%d", &a[i]);
	}
	dfs(0,1,a[0]);
	printf("%d", max);
	return 0;
}