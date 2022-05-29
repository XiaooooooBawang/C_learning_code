#include<stdio.h>
#include<string.h>
int main()
{
	char cChar1[256] = {0}, cChar2[128] = { 0 };
	int length1,length2;
	printf("please input cChar1:\n");
	scanf_s("%s", cChar1,128);
	printf("please input cChar2:\n");
	scanf_s("%s", cChar2,128);
	length1=strlen(cChar1);
	length2 = strlen(cChar2);
	strcat_s(cChar1, 256, cChar2);
	printf("the char is:\n");
	puts(cChar1);
}