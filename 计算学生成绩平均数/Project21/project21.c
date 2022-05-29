#include<stdio.h>
float Average(float* Score);
int i;
float Student[10];
int main()
{
	printf("please enter 10 students' score:\n");
	for (i = 0; i < 10; i++)
	{
		printf("Student[%d]=", i);
		scanf_s("%f", Student+i);/*©ирт&Student[i]*/
	}
	printf("the average score is :%.2f", Average(Student));
	return 0;
}
float Average(float* Score)
{
	float sum=0;
	float result;
	for (i = 0; i < 10; i++)
	{
		sum = sum + Score[i];
	}
	result = sum / 10;
	return result;
}