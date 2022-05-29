#include<stdio.h>
#include<stdlib.h>
int main()
{
	int** Array, i,j;
	Array = (int**)malloc( sizeof(int*)*2);
	if (Array == NULL)
	{
		printf("fail");
	}
	else
	{
		for (i = 0; i < 2; i++)
		{
			Array[i] = (int*)malloc(sizeof(int)*2);
			if (Array[i] == NULL)
			{
				printf("fail");
			}
			else
			{
				printf("please input 4 number into the Array:\n");
				for (i = 0; i < 2; i++)
				{

					for (j = 0; j < 2; j++)
					{
						scanf_s("%d", &Array[i][j]);
					}
				}
				for (i = 0; i < 2; i++)
				{
					for (j = 0; j < 2; j++)
					{
						printf("Array[%d][%d]=%d\n", i, j, Array[i][j]);
					}
				}
			}
		}
	}
	for (i = 0; i < 2; i++)
		free(Array[i]);
	free(Array);
	return 0;
}