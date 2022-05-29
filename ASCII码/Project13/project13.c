#include<stdio.h>
int main()
{
	printf("ASCII   big number\n");
	int iASCII;
	for (iASCII = 65; iASCII <= 90; iASCII++)
	{
		printf("  %d      %c\n", iASCII, iASCII);
	}
}