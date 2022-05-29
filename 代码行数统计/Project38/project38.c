#include <stdio.h>
#include <stdlib.h>
#include<process.h>
int main()
{
	int count = 0;
	FILE* fp;
	FILE* cp;
	char ch = {0};
	char name[100] = {0};
	errno_t err;
	if ((err = fopen_s(&fp, "C:/Users/小霸王/Desktop/data", "r")) != 0)
	{
		printf("can not open1!");
		exit(0);
	}
	while ((fscanf_s(fp, "%s", name, 100)) == 1)
	{
		if ((err = fopen_s(&cp, name, "r")) != 0)
		{
			printf("can not open2!");
			exit(0);
		}
		while ((ch = fgetc(cp))!= EOF)
			{
					if (ch == '\n')
						count++;
			}	
	}
	
	printf("这个暑假我写了%d行代码，完成了“十万行代码”目标的%d%%\n", count,count/1000);
	fclose(fp);
}