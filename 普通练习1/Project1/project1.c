#include<stdio.h>
#define Height 10
int calculate(int Length, int Width);
int m_Length;
int m_Width;
int result;
int calculate(int Length, int Width)
{
	int result = Length * Width * Height;
	return result;
}
int main()
{
	printf("长方形的高度是：%d\n", Height);

	printf("请输入长度\n");
	scanf_s("%d", &m_Length);

	printf("请输入宽度\n");
	scanf_s("%d", &m_Width);
	result = calculate(m_Length, m_Width);
	printf("长方体的体积是");
	printf("%d", result);
	return 0;
}