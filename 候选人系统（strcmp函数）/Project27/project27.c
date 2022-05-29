#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	printf("--------candidate select system-----------");
	printf("candidate:\n");
	printf("zou\t\tjun\t\tzhi\n");
	printf("if you want to quit,input q;");
	printf("please input your selection:\n");
	int count1=0,count2=0,count3=0;
	char cChar[5] = {0};
	do
	{
		gets_s(cChar, 5);
		if (strcmp(cChar,"zou") == 0)
			count1++;
		if (strcmp(cChar, "jun") == 0)
			count2++;
		if (strcmp(cChar, "zhi") == 0)
			count3++;
	} while (strcmp(cChar, "q") != 0);
	
	printf("zou has %d ticket\n",count1);
	printf("jun has %d ticket\n", count2);
	printf("zhi has %d ticket\n", count3);
	return 0;
}