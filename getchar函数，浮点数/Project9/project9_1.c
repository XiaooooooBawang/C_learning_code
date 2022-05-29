#include<stdio.h>
int main()
{
	char cBig, cSmall;
	printf("please input the small letter:");
	cSmall = getchar();
	cBig = cSmall - 32;
	printf("the big letter is :%c\nthe big letter's ASCII is:%d",cBig, cBig);
	return 0;
}