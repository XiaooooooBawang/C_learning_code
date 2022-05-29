#include<stdio.h>   /*别运行，我把两种方法合在一起了，有两个main主体*/
/*以下只能实现输入10位整数*/
int count=0;
int reverse(int num)    /*反转只需对sum*/
{
	int j, w = 0;
	while (num!=0)
	{
		j = num % 10;
		num /= 10;
		w = w * 10 + j;   /*实现了整数反转，genius idea*/
		count++;    /*统计位数只需对求出的总和sum，原先输入的数字只需对每一位求和，不需统计位数*/
	}
	return w;
};
int main()
{
	int n, a, b, c, sum = 0, i;
	scanf_s("%d", &n);
	do
	{
		a = n / 10;
		b = n % 10;
		sum += b;
		n = a;
	} while (n!=0);
	i = reverse(sum);
	while (i!=0)
	{
		c = i % 10;
		i /= 10;
		count--;
		switch (c)
		{
		case 0:
			printf("ling");
			break;
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		default:
			break;
		}
		if (count != 0)
		{
			printf(" ");
		}
	}
}


/*以下要用数组才可以实现10位数以上的输入，满足pta的题设*/
int main()
{
	char number[100];
	int sum=0,j,c;
	scanf_s("%s", number,100);
	for (int i = 0; number[i]!='\0'; i++)
	{
		sum += (number[i] - 48);  /*48是“0”字符的ASCII码，因为num定义的是字符型，所以其每个元素代表的数字以ASCII码存储*/
	}

	j = reverse(sum);            /*得出sum后面就跟上面的一样*/
	while (j != 0)
	{
		c = j % 10;
		j /= 10;
		count--;
		switch (c)
		{
		case 0:
			printf("ling");
			break;
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		default:
			break;
		}
		if (count != 0)
		{
			printf(" ");
		}
	}
}