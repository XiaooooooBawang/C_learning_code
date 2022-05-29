#include <stdio.h>
#include <string.h>
void foo(char* p, char* q, char* c)
{
	int k = 0;
	while (*p !='\0' || * q != '\0')
	{
		if (*p < *q) c[k] = *q;
		else c[k] = *p;
		if (*p) p++;
		if (*q) q++;
		k++;
	}
}
int main()
{
	char a[10] = "aBCDeFgh", b[10] = "ABcd", c[80] = { 0 };
	foo(a, b, c);
	printf("The string a:"); puts(a);
	printf("The string b:"); puts(b);
	printf("21009190075-邹俊智-C语言规范作业结果:"); puts(c);
	return 0;
}