#include<stdio.h>
int main()
{
	extern char cChar;
	printf("%c", cChar);
	return 0;
}