#include<stdio.h>
#include<process.h>
#include<string.h>
main()
{
	FILE *fp1,*fp2;
	char filename[30] = { 0 }, str1[30] = { 0 }, str2[30] = { 0 }, str[30] = {0};
	errno_t err;
	printf("please input the filename of the text you want to copy:\n");
	scanf_s("%s", filename, strlen(filename));
	if ((err = fopen_s(&fp1,filename, "r+"))!= 0)
	{
		printf("can not open! \n");
		exit(0);
	}
	printf("please input the string into the first file:\n");
	scanf_s("%s", str1, 30);
	fputs(str1, fp1);
	fgets(str2, sizeof(str2), fp1);
	fclose(fp1);
	printf("please input the filename of the text you want to paste:\n");
	scanf_s("%s", filename, strlen(filename));
	if ((err = fopen_s(&fp2,filename, "r+")) != 0)
	{
		printf("can not open!\n");	
		exit(0);
	}
	fputs(str2, fp2);
	fgets(str, sizeof(str), fp2);
	printf("%s", str);
	fclose(fp2);

}