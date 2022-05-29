#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
int main()
{
	string str;
	string t;
	getline(cin,str);
	vector<string> isOrder;
	stringstream input(str);
	int flag=0;
	while (input >> t)
	{
		if (t[0] == '-')
		{
			isOrder.push_back(t);
			flag = 1;
		}
	}
	if (!flag)
	{
		cout << "no";
		return 0;
	}
	for (unsigned int i = 0; i < isOrder.size()-1; i++)
	{
		for (unsigned int j = i+1; j < isOrder.size(); j++)
		{
			if (isOrder[i] == isOrder[j])
			{
				isOrder.erase(isOrder.begin()+j);
			}
		}
	}
	sort(isOrder.begin(), isOrder.end());
	for (unsigned int i = 0; i < isOrder.size(); i++)
	{
		cout <<isOrder[i]<< " ";
	}
}