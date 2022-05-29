#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
	int a,b;
	char op='+';
	string str,t;
	getline(cin, str);
	vector<string> res;
	vector<string> number;
	stringstream input (str);
	while (input >> t)
	{
		res.push_back(t);
	}
	for (unsigned int i = 0; i < res.size(); i++)
	{
		if (res[i] == "+")
		{
			op = '+';
		}
		else if (res[i] == "-")
		{
			op = '-';
		}
		else if (res[i] == "*")
		{
			op = '*';
		}
		else if (res[i] == "/")
		{
			op = '/';
		}
		else if (res[i] == "%")
		{
			op = '%';
		}
		else
		{
			number.push_back(res[i]);
		}
	}
	a = stoi(number[0]);
	b = stoi(number[1]);
	if (op == '+')
	{
		cout << a + b;
	}
	else if (op == '-')
	{
		cout << a - b;
	}
	else if (op == '*')
	{
		cout << a * b;
	}
	else if (op == '/')
	{
		cout << a / b;
	}
	else if (op == '%')
	{
		cout << a % b;
	}
}
