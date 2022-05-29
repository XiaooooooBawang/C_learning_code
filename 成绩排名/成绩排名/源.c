#include<stdio.h>
int main()
{
	int n,i,j;
	scanf_s("%d", &n);
	struct Student
	{
		char name[20];
		char num[20];
		int grade;
	}stu[105] = {0};
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", stu[i].name, 20);
		scanf_s("%s", stu[i].num, 20);
		scanf_s("%d", &stu[i].grade);
	}

	/*ÅÅĞòËã·¨*/
	struct Student temp;
	int min;
	for (i = 0; i < (n-1); i++)
	{
		min = stu[i].grade;
		for ( j = i+1; j < n; j++)
		{
			if (stu[j].grade<=min)
			{
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	printf("%s %s\n", stu[n - 1].name, stu[n - 1].num);
	printf("%s %s", stu[0].name, stu[0].num);
}