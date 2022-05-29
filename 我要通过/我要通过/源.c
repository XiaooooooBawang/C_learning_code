/*
  ①只能有PAT三种字符
  ②PT各自只能有一个
  ③A至少有一个
  ④P在T左边
  ⑤PT间至少有一个A
  ⑥P左边的A*PT之间的A=T右边的A
  ⑦p左的A与t右的A关于PAT对称
  */
#include<stdio.h>
#include<string.h>
int main()
{
	char str[100] = {0};
	int n,i,j,len;   /*循环借助变量*/
	int pi, ti;     /*pat各自的位置*/
	int pleft = 0, pt = 0, tright = 0;   /*p左边、pt间、t右边a的个数*/
	int pnum=0, anum=0,tnum=0;   /*pat各自字符的数量*/
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%s", str,100);
		len = strlen(str);
		for (j = 0; j < len; j++)         /*统计pat各自数量*/
		{
			if(str[j]=='P')
			{
				pi = j;
				pnum++;
			}
			else if (str[j] == 'A')
			{
				anum++;
			}
			else if (str[j] == 'T')
			{
				ti = j;
				tnum++;
			}
		}
		pleft = pi - 0;
		pt = ti - pi - 1;             
		tright = len - ti - 1;
		if (pnum!=1||tnum!=1||anum==0||pi>=ti||(pnum+anum+tnum)!=len||pt<1)   /*先把没A，P在T右边，出现其他字符的先砍掉*/
		{
			printf("NO\n");
		}
		else                                /*然后就是对只有pat字符的进行数学上排除*/
		{
			if (pt=1)
			{
				if (pleft!=tright)
				{
					printf("NO\n");
				}
				else
				{
					printf("YES\n");

				}
			}
			else
			{
				if ()
				{

				}
			}
		}
	}
	|| (pi - 0) * (ti - pi - 1) != (len - ti - 1)
}