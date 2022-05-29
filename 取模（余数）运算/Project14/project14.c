#include<stdio.h>
int main()
{
	int i;
	printf("0-100中不能被3整除的数有：\n");
	for (i = 0; i <= 100; i++)
	{
		if (i%3==0)
		{
			continue;
		}
		printf("%d , ", i);
	}
	return 0;
}