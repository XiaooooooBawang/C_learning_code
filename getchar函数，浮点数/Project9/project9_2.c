#include<stdio.h>
int main()
{
	float iMoney, iBasic, iImprove, iNum;
	printf("the basic money is:");
	scanf_s("%f", &iBasic);
	printf("the good's number is:");
	scanf_s("%f", &iNum);
	iImprove = iNum * 1.5f;
	iMoney = iBasic + iImprove;
	printf("the monthly money is:%.2f", iMoney);
	return 0;
}