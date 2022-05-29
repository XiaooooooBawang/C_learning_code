#include<stdio.h>
int main()
{
	int k,j,t=0,max,temp;
	int a[100] = { 0 }, b[5000] = { 0 }, c[100] = {0};  /*pta中编译器允许吧b【比较大】，也只有比较大才能通过，但vs不能太大*/
	scanf_s("%d", &k);
	/*记录过程*/
	for (int i = 0; i < k; i++)
	{
		scanf_s("%d", &a[i]);
		j = a[i];     
		if (b[j]==1)   /*只需对输入的数进行判断是否被验证过，因为不可能出现验证过程中的某个数没被验证过*/
		{
			continue;
		}
		b[j] = 0;      /*很好的想法：定义b这个数组，相当于搞了张数表，操作完后就在表上为每个数标上是否已覆盖（1是0否），最后再对表上的数检验排序*/
		while (j!=1)
		{
			if (j%2==0)
			{
				j /= 2;
				b[j] = 1;
			}
			else
			{
				j = (3 * j+1) / 2;
				b[j] = 1;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (b[a[i]]!=1)
		{
			c[t] = a[i];
			t++;
		}
	}
	/*排序过程*/
	for (int i = 0;  i < t;  i++)
	{
		max = c[i];
		for (int n = i+1; n <t+1 ; n++)
		{
			if (c[n]>=max)
			{
				temp = c[n];
				c[n] = c[i];
				c[i] = temp;
			}
		}
	}
	for (int i =0 ; i <t; i++)
	{
		printf("%d", c[i]);
		if (i!=t-1)
		{
			printf(" ");
		}
	}
	return 0;
}


