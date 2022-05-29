#include<stdio.h>
int main()
{
	int a[1000] = { 0 }, n, sum = 0, book[1000] = { 0 }, max;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
			{
				max = (((a[i] > a[j]) ? a[i] : a[j]) > a[k]) ? ((a[i] > a[j]) ? a[i] : a[j]) : a[k];
				if (a[i] + a[j] == a[k] || a[i] + a[k] == a[j] || a[j] + a[k] == a[i] && book[max] == 0)
				{
					book[max] = 1;
					sum++;
				}
			}
	printf("%d", sum);
}
