#include<stdio.h>
main()
{
	int i,t,a[10];
	printf("please input : \n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < 5; i++)
	{
		t = a[9-i];
		a[9-i] = a[ i];
		a[i] = t;
	}
	printf("the reverse is :\n");
	for (i = 0; i < 10; i++)
	{
		printf(" %5d", a[i]);
	}
}