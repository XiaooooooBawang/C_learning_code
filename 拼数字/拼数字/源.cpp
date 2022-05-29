#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	string num;
	getline(cin, str);
	int flag = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num += str[i];
			flag = 1;
		}
	}
	if (!flag)
	{
		cout << "0";
		return 0;
	}
	int number = stoi(num);
	if (number == 0)
	{
		cout << "0";
	}
	else
	{
		for (int i = number - 1; i > 1; i--)
		{
			if (number % i == 0)
			{
				cout << i;
				return 0;
			}
		}
		cout << number;
	}
}