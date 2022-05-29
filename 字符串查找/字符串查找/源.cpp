#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string part,t;
	vector<string> home,temp;
	getline(cin, part);
	int op, n;
	cin >>op >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		getline(cin, t);
		home.push_back(t);
	}
	if (op)
	{
		for (unsigned int i = 0; i < home.size(); i++)
		{
			if (home[i].find(part) != home[i].npos)
			{
				cout << home[i] << "\n";
			}
		}
	}
	else
	{
		temp = home;
		transform(part.begin(), part.end(), part.begin(), ::tolower);
		for (unsigned int i = 0; i < home.size(); i++)
		{
			transform(home[i].begin(), home[i].end(), home[i].begin(), ::tolower);
			if (home[i].find(part) != home[i].npos)
			{
				cout << temp[i] << "\n";
			}
		}
	}
}