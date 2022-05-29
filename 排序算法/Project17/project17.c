#include<stdio.h>
int main()
{
	int i, j,iMin,iGrade[12],iTemp;
	printf("please enter studens's grade :\n");
	for (i = 0; i <12; i++)
	{
			printf("cGrade[%d]=", i);
			scanf_s("%d",&iGrade[i]);
			printf("\n");
	}
	/*Ñ¡Ôñ·¨ÅÅÐò*/
	for (i = 0; i < 11; i++)
	{
		iMin = iGrade[i];
		for (j = i + 1; j < 12; j++)
		{
			if (iGrade[j] <= iMin)
			{
				iMin= iGrade[j];
				iGrade[j] = iGrade[i];
				iGrade[i] = iMin;
			}
		}
	}
	printf("the grade's order is:\n");
	for (i = 0; i < 12; i++)
	{
		printf("%d\t", iGrade[i]);
		if (i == 3 || i == 7)
			printf("\n");
	}
	printf("\n");
/*Ã°ÅÝ·¨ÅÅÐò*/
	for (i = 1; i < 11; i++)
	{
		for (j = 11; j >= i; j--)
		{
			if (iGrade[j] <= iGrade[j - 1])
			{
				iMin = iGrade[j];
				iGrade[j] = iGrade[j-1];
				iGrade[j-1] = iMin;
			}
		}
	}
	printf("the grade's order is:\n");
	for (i = 0; i < 12; i++)
	{
		printf("%d\t", iGrade[i]);
		if (i == 3 || i == 7)
			printf("\n");
	}
	printf("\n");
/*½»»»·¨ÅÅÐò*/
	for (i = 0; i < 12; i++)
	{
		for (j = i + 1; j < 12; j++)
		{
			if (iGrade[j] <= iGrade[i])
			{
				iMin = iGrade[j];
				iGrade[j] = iGrade[i];
				iGrade[i] = iMin;
			}
		}
	}
	printf("the grade's order is:\n");
	for (i = 0; i < 12; i++)
	{
		printf("%d\t", iGrade[i]);
		if (i == 3 || i == 7)
			printf("\n");
	}
	printf("\n");
/*²åÈë·¨ÅÅÐò*/
	for (i = 1; i < 12; i++)
	{
		iTemp = iGrade[i];
		j = i - 1;
		while ((j >= 0) && (iTemp <= iGrade[j]))
		{
			iGrade[j + 1] = iGrade[j];
			j--;
		}
		iGrade[j + 1] = iTemp;
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