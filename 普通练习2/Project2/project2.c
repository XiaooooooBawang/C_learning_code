#include<stdio.h>
#define PAI 3.141592653589793;

int main()
{
	double R;
	double Result=0;
	printf("请输入圆半径：");
	scanf_s("%lf", &R);
	Result = R * R * PAI;
	printf("圆的面积是：%lf", Result);
	return 0;
}