#include<stdio.h>
#define MUL(a,b) (a)*(b)
#define MIN(a,b,c) (((a)<(b)?(a):(b))<(c)?((a)<(b)?(a):(b)):(c))

int main()
{
	int x, y,z;
	printf("please input two number:\n");
	scanf_s("%d%d", &x, &y);
	printf("the multiply is :%d\n", MUL(x, y));
	printf("please input three number:\n");
	scanf_s("%d%d%d", &x, &y,&z);
	printf("the min number is :%d", MIN(x, y, z));
}