#include<stdio.h>
#include<string.h>
#include<math.h>
char map[50][50];
int book[50][50];
int main()
{
	int n,m,c,step=0,nowx,nowy;
	scanf("%d %d %d ",&n,&m,&c);
	for(int i=0;i<n;i++)
	{
		gets(map[i]);
	}
	nowx=0;
	nowy=c-1;
	book[nowx][nowy]=1;
	while(1)
	{
		switch(map[nowx][nowy])
		{
			case 'W':
				nowy--;
				break;
			case 'E':
				nowy++;
				break;
			case 'S':
				nowx++;
				break;
			case 'N':
				nowx--;
				break;
		}
		step++;
		if((nowx>=n||nowx<0)||(nowy>=m||nowy<0))
		{
			printf("out %d",step);
			break;
		}
		else
		{
			if(book[nowx][nowy]==1)
			{
				printf("loop %d",step);
				break;
			}
			else
			{
				book[nowx][nowy]=1;
			}
			
		}
	}
} 
