#include<stdio.h>
int main()
{
	int a, b, c,t;
	for (int i = 100; i < 1000; i++)
	{
		t = i;
		a = t % 10;
		t /=  10;
		b = t % 10;
		t /=  10;
		c = t % 10;
		if (a*a*a + b*b*b + c*c*c == i)
			printf("%d ", i);
	}
	return 0;
}