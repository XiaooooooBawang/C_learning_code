#include<stdio.h>     //要使用如下完全二叉树的性质要求堆是从h【1】开始，h【0】舍去
int heap[101];
int n,num;
void swap(int x, int y)     //交换的是x和y号节点的值
{
	int temp;
	temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
};

void siftdown(int w)
{
	int t, flag = 0;
	while (flag == 0 && 2 * w <= n)       //至少有左儿子就能继续调整   //建堆和取出最小值两处都要用到向下调整，所以条件要考虑周到
	{
		if (heap[w] > heap[2 * w])
		{
			t = 2 * w;
		}
		else
		{
			t = w;
		}
		if ((2 * w + 1) <= n)    //如果有右儿子
		{
			if (heap[t] > heap[2 * w + 1])
			{
				t = 2 * w + 1;
			}
		}
		if (t != w)
		{
			swap(w, t);
			w = t;
		}
		else
		{
			flag = 1;
		}
	}
};

void creat()       //建堆，每个小树的值是向下调整，但对整个大树是节点向上调整
{
	for (int i = n/2; i >=1; i--)     //向上调整
	{
		siftdown(i);        //向下调整
	}
};
int deletemin()      //取出最小值
{
	int j;
	j = heap[1];
	heap[1] = heap[n];
	n--;
	siftdown(1);    //从第一个节点开始调整
	return j;
};
int main()
{
	scanf_s("%d", &num);
	n = num;     //num是堆真实的大小，n是堆可处理的大小，到时deletemin会n--来减小堆可处理的大小
	for (int i = 1; i <= num; i++)
	{
		scanf_s("%d", &heap[i]);
	}
	creat();
	for (int i = 1; i <= num; i++)
	{
		printf("%d ",deletemin());
	}
}