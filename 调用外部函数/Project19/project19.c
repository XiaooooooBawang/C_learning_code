#include<stdio.h>

extern char* GetString(char* pString);			/*声明外部函数*/
extern void ShowString(char* pString);			/*声明外部函数*/

int main()
{
	char* pMyString;							/*定义字符串变量*/
	pMyString = GetString("Hello!");				/*调用函数为字符串赋值*/
	ShowString(pMyString);						/*显示字符串*/

	return 0;
}
