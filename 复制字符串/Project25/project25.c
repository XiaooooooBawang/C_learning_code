#include<stdio.h>
int main()
{
	char str1[128] , * str2;
	printf("please input str1:\n");
	gets_s(str1, 128);
	str2 = str1;
	printf("the copy one is:\n");
	puts(str2);
}