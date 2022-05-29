#include<stdio.h>
int main()
{
	int a[3][2] ,num,sum,min=999999;
	scanf_s("%d", &num);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
		{
			scanf_s("%d",&a[i][j]);
		}
	for (int i = 0; i < 3; i++)
	{
		if (num%a[i][0]==0)
		{
			sum = num / a[i][0] * a[i][1];
		}
		else
		{
			sum = (num / a[i][0] + 1) * a[i][1];
		}
		if (sum<min)
		{
			min = sum;
		}
	}
	printf("%d", min);
	return 0;
}