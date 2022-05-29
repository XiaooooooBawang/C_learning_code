#include<stdio.h>     //要使用如下完全二叉树的性质要求堆是从h【1】开始，h【0】舍去
//找第k大（小）的数就建大小为k的最小（大）堆，将其余的每个数与堆顶比较，小（大）于堆顶不要，大（小）于堆顶就交换，调整堆，继续比较至结束，最后的堆顶就是第k大（小）的数

int heap[101];
int  num, k;
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
	while (flag == 0 && 2 * w <= k)       //至少有左儿子就能继续调整   //建堆和取出最小值两处都要用到向下调整，所以条件要考虑周到
	{
		if (heap[w] > heap[2 * w])
		{
			t = 2 * w;
		}
		else
		{
			t = w;
		}
		if ((2 * w + 1) <= k)    //如果有右儿子
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

void creat(int j)       //建堆，每个小树的值是向下调整，但对整个大树是节点向上调整
{
	for (int i = j / 2; i >= 1; i--)     //向上调整
	{
		siftdown(i);        //向下调整
	}
};
int main()
{
	scanf_s("%d", &num);
	scanf_s("%d", &k);        //求第k大的数
	for (int i = 1; i <= num; i++)
	{
		scanf_s("%d", &heap[i]);
	}
	creat(k);
	for (int i = k+1; i <=num ; i++)
	{
		if (heap[i] <= heap[1])
			continue;
		else
		{
			swap(1, i);
			siftdown(1);
		}
	}
	printf("%d", heap[1]);
}