#include<stdio.h>
struct Day
{
	int a;
	int b;
	int sum;
}day[7];
int main()
{
	int max=0;
	for (int i = 0; i < 7; i++)
	{
		scanf_s("%d%d", &day[i].a, &day[i].b);
		day[i].sum = day[i].a + day[i].b;
	}
	for (int i = 0; i < 7; i++)
	{
		if (max<day[i].sum)
		{
			max = day[i].sum;
		}
	}
	if (max > 8)
	{
		for (int i = 0; i < 7; i++)
		{
			if (day[i].sum == max)
			{
				printf("%d", i + 1);
				break;
			}
		}
	}
	else
		printf("0");
	return 0;
}