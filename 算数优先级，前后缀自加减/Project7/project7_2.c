#include<stdio.h>
int main()
{
	int a;
	printf("please input:");
	scanf_s("%d", &a);
	a += a *= a /= a - 6;
	printf("the result is %d",a);
	return 0;
}