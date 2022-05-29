#include<stdio.h>
int main()
{
	int x, y,z,w;
	printf("请输入两个数进行按位运算:\n");
	scanf_s("%d%d", &x, &y);
	printf("按位与运算结果是：%o\n", x & y);
	printf("按位或运算结果是：%o\n", x | y);
	printf("请输入一个数用于左右移：\n");
	scanf_s("%d", &z);
	printf("该数左移两位后结果是：%o\n", z << 2);
	printf("该数右移两位后结果是：%o\n", z >> 2);
	printf("请输入一个数用于循环左右移：\n");
	scanf_s("%d", &w);
	printf("该数循环左移两位后结果是：%o\n", (w>>(32-2)|w<<2));
	printf("该数循环右移两位后结果是：%o\n", (w<< (32- 2) | w >> 2));
}