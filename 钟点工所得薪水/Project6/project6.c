#include<stdio.h>
int main()
{
	int iHoursWorked , iHoursRate , iMoney;
	printf("工作时间：");
	scanf_s("%d",&iHoursWorked);
	printf("时薪是：");
	scanf_s("%d",&iHoursRate);
	iMoney = iHoursRate * iHoursWorked;
	printf("一天工资是：%d\n", iMoney);
	return 0;
}