#include<stdio.h>
int main()
{
	int iNum1, iNum2, iNum3,iBigger,iMax;
	printf("please enter three number:\n");
	scanf_s("%d%d%d",& iNum1, &iNum2,& iNum3);
	iBigger = (iNum1 >= iNum2) ? iNum1 : iNum2;
	iMax = (iBigger >= iNum3) ? iBigger : iNum3;
	printf("the biggest number is:%d", iMax);
	return 0;
}