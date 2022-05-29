#include<stdio.h>
int main()
{
	int iNum = 6, iNumPreAdd, iNumPreDel, iNumLastAdd, iNumLastDel;
	iNumPreAdd = ++iNum;
	iNumLastAdd = iNum++;
	printf("原来数：%d", iNum);
	printf("前缀自加：%d", iNumPreAdd);
	printf("后缀自加：%d", iNumLastAdd);
	iNum = 6;
	iNumPreDel = --iNum;
	iNumLastDel = iNum--;
	printf("前缀自减：%d", iNumPreDel);
	printf("后缀自减：%d", iNumLastDel);
	return 0;
}