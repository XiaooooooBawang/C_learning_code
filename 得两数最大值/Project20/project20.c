#include<stdio.h>
int Max(int a, int b);
int main()
{
	int num1, num2,max;
	printf("please enter two number:\n");
	scanf_s("%d%d", &num1, &num2);
	max = Max(num1, num2);
	printf("the max number is:%d", max);
	return 0;
}
int Max(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}