#include<iostream>
#include<string>
int main()
{
	int n,flag=1;
	std::string str;
	std::cin >> n;
	while (n!=0)
	{
		for (int i = 0; i < n % 4; i++)
		{
			switch (flag)
			{
			case 1:
				str.insert(0, "*");
				break;
			case 2:
				str.insert(0, "(");
				break;
			case 3:
				str.insert(0, "O");
				break;
			case 4:
				str.insert(0, "W");
				break;
			default:
				break;
			}
		}
		n /= 4;
		flag++;
	}
	std::cout << str<<std::endl;
}