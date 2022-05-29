#include<stdio.h>
int main()
{
	int h,m;
	float t;
	scanf("%d%d",&h,&m);
	t=h+m/60.000;
	printf("%.2f",4*t*t/(t+2)-20);
}
