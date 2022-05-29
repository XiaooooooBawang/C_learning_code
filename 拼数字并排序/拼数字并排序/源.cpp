#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	int head=0, tail=0;
	string str;
	vector<string> snum;
	vector<int> num;
	getline(cin,str);
	str.insert(0, "a");
	str.insert(str.length(), "a");//str += 'a';
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] < '0' || str[i]>'9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			head = i + 1;
		}
		if ((str[i + 1] < '0' || str[i + 1]>'9') && (str[i] >= '0' && str[i] <= '9'))
		{
			tail = i;
			snum.push_back(str.substr(head, tail - head + 1));
		}
	}
	for (int i = 0; i < snum.size(); i++)
	{
		//num.push_back(atoi(snum[i].c_str()));//这是const *char类型（cstring）用atoi
		num.push_back(stoi(snum[i]));        //const *string(c++的string)
	}
	sort(num.begin(), num.end(),greater<int>());
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << ' ';
	}
}

/*c做法
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<math.h>
char str[110], cnum[11][101], tstr[101];
int num[11];
int main()
{
	int len, head, tail, cnt = 0, t;
	gets(tstr);
	str[0] = 'a';
	strcat(str, tstr);
	len = strlen(str);
	str[len] = 'a';
	for (int i = 0; i < len; i++)
	{
		if ((str[i] < '0' || str[i]>'9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			head = i + 1;
		}
		if ((str[i + 1] < '0' || str[i + 1]>'9') && (str[i] >= '0' && str[i] <= '9'))
		{
			tail = i;
			for (int j = head; j <= tail; j++)
			{
				cnum[cnt][j - head] = str[j];
			}
			num[cnt] = atoi(cnum[cnt]);
			cnt++;
		}
	}
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = 0; j < cnt - 1 - i; j++)
		{
			if (num[j] < num[j + 1])
			{
				t = num[j];
				num[j] = num[j + 1];
				num[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", num[i]);
	}
}*/
