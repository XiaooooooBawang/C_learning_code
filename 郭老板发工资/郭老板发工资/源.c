#include<stdio.h>
int main()
{
	int k,sum=0;
	scanf_s("%d", &k);
	for (int n = 1; n < 50; n++)
	{
		if ((n+1)*n/2==k)
		{
			sum = n*(n+1)*(2*n+1)/6;
			break;
		}
		if ((n + 1) * n / 2 > k)
		{
			sum = (n-1)*n*(2*n-1)/6 + (k-(n-1)*n/2)*n;
			break;
		}
	}
	printf("%d", sum);
	return 0;
}