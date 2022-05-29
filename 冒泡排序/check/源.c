/*#include<stdio.h>
int main()
{
	int a[10],t;
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j <9-i; j++)    //要注意j+1不越界
		{
			if (a[j]>a[j+1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i <9; i++)
	{
		printf("%d ", a[i]);
	} 
	return 0;
}*/
#include<stdio.h>
#include<string.h>
char name[100][21];
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", name[i],20);
		strlwr(name[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (name[i][j] >= 97 && name[i][j] <= 122)
			{
				name[i][j] -= 32;
				break;
			}
		}
		printf("%s\n", name[i]);
	}
	return 0;
}