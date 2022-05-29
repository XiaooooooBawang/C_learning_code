#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct can
{

	char name[10];
	int count;
}per[3] = { {"zou",0},{"jun",0},{"zhi",0}};
int main()
{
	printf("--------candidate select system-----------");
	printf("candidate:\n");
	printf("zou\t\tjun\t\tzhi\n");
	printf("you have 10 ticket ,if you want to quit,input quit;");
	printf("please input your selection:\n");
	int i, j;
	char inname[10];
	for ( i = 0; i < 10; i++)
	{
		gets_s(inname, 10);
		for ( j = 0; j < 3; j++)
		{
			if (strcmp(inname,per[j].name)==0)
			{
				per[j].count++;
			}
		}
	}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%s:\t%d\n", per[i].name, per[i].count);
	}
}
