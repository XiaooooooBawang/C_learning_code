#include<stdio.h>
int main()
{
	int value;
	printf("please enter a number:");
	scanf_s("%d", &value);
	if (value==1)
	{
		printf("hiha!");
	}
	else if (value == 0)
	{
		printf("bibi!");
	}
	else
	{
		printf("oh no!");
	}
	return 0;
}