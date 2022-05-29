#include<stdio.h>
int a[100], n;
void quicksort(int left, int right)   /*left是要排序数列段最左的位数，right是...右*/
{
	int i, j, temp, t;
	if (left >= right)    /*递归的时候如果left>=right即已排序完了，return退出*/
		return;
	temp = a[left];   /*以最左边的数为基准数，用temp记录*/
	i = left;
	j = right;    /*i,j是哨兵*/
	while (i<j)
	{
		while (a[j] >= temp && i < j)       /*让哨兵前进*/ /*必须得是先从右边开始*/  //右哨兵比基准数小才停
		{
			j--;
		}
		while (a[i] <= temp && i < j)      //左哨兵比基准数大才停
		{
			i++;
		}
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];    /*在ij没相遇之前将符合条件的两数交换*/
			a[j] = t;
		}
	}
	a[left] = a[i];    /*将结束位（i或j）的数与基准数交换，使基准数归位*/
	a[i] = temp;
	quicksort(left, i - 1);
	quicksort(i + 1, right);      /*函数内调用函数自己实现递归*/    /*第i位已归位*/
};
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}