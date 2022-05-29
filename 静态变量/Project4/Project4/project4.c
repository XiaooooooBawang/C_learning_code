#include<stdio.h>
void calculate ()
{
	static int num = 3;
	num = num * 3;
	printf("%d\n", num);
}
int main()
{
	printf("3的平方是：");
	calculate();
	printf("3的立方是：");
	calculate();
	return 0;
}