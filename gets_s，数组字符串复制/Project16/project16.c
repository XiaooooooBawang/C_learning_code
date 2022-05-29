#include<stdio.h>
char String[128] = { 0 }, Stringcpy[128] = { 0 };
int i,count=0;
int main()
{
	printf("please enter chars:");
	gets_s(String,128);
	while (count<128)
	{
		if (String[count] != '\0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i <= count; i++)
	{
		Stringcpy[i] = String[i];
	}
	printf("%s", Stringcpy);
	return 0;
}