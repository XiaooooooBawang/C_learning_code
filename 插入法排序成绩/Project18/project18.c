#include<stdio.h>
int main()
{
	int i, j, iTemp, iGrade[12];
	printf("please enter studens's grade :\n");
	for (i = 0; i < 12; i++)
	{
		printf("cGrade[%d]=", i);
		scanf_s("%d", &iGrade[i]);
		printf("\n");
	}
	for (i = 1; i < 12; i++)
	{
		iTemp = iGrade[i];
		j = i - 1;
		while ((j >= 0) && (iTemp <= iGrade[j]))
		{
			iGrade[j+1] = iGrade[j];
			j--;
		}
		iGrade[j+1] = iTemp;
	}
	printf("the grade's order is:\n");
	for (i = 0; i < 12; i++)
	{
		printf("%d\t", iGrade[i]);
		if (i == 3 || i == 7)
			printf("\n");
	}
	printf("\n");
}