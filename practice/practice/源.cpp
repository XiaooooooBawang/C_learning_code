#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<functional>
#include<algorithm>
#include<stack>
#include<iomanip>
using namespace std;
/*int main() {
	string str,left,right;
	getline(cin, str);
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] > str[0]) {
			left += str[i];
		}
		else {
			right += str[i];
		}
	}
	sort(right.begin(), right.end());
	cout << left << str[0] << right;
}
int main() {
	string t;
	vector<string> str;
	unsigned int max=0;
	getline(cin, t);
	while (t != "***end***") {
		str.push_back(t);
		getline(cin, t);
	}
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i].length() > max) {
			max = str[i].length();
		}
	}
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i].length() == max) {
			cout << max<<"\n" << str[i];
		}
	}
}
bool judge(string str) {
	stack<char> mystack;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
			mystack.push(str[i]);
			break;
		case ')':
			if (mystack.empty()) {
				return false;
			}
			if (mystack.top() == '(') {
				mystack.pop();
			}
			else {
				return false;
			}
			break;
		case ']':
			if (mystack.empty()) {
				return false;
			}
			if (mystack.top() == '[') {
				mystack.pop();
			}
			else {
				return false;
			}
			break;
		case '}':
			if (mystack.empty()) {
				return false;
			}
			if (mystack.top() == '{') {
				mystack.pop();
			}
			else {
				return false;
			}
			break;
		}
	}
	return mystack.empty();
}
int main() {
	string	str;
	getline(cin, str);
	if (judge(str)) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}
int main() {
	string substr,str[100],t;
	int flag, n;
	cin >> substr >> flag >> n;
	cin.get();
	if (flag==0)
	{
		transform(substr.begin(), substr.end(), substr.begin(), ::tolower);
	}
	for (int i = 0; i < n; i++)
	{
		getline(cin, str[i]);
		if (flag==1)
		{
			if (str[i].find(substr) != string::npos)
			{
				cout << str[i]<<"\n";
			}
		}
		else
		{
			t = str[i];
			transform(t.begin(), t.end(), t.begin(), ::tolower);
			if (t.find(substr) != string::npos)
			{
				cout << str[i]<<"\n";
			}
			
		}
	}
}
int main() {
	string str,t;
	getline(cin,str);
	vector<string> mystr;
	stringstream input(str);
	while (input>>t)
	{
		mystr.push_back(t);
	}
	for (unsigned int i = 0; i < mystr.size(); i++)
	{
		if (mystr[i] == "+") {
			mystr.erase(mystr.begin()+i);
			//mystr.insert(mystr.end(), "+");
			cout << stoi(mystr[0]) + stoi(mystr[1]);
		}
		else if (mystr[i] == "-")
		{
			mystr.erase(mystr.begin() + i);
			cout << stoi(mystr[0]) - stoi(mystr[1]);
		}
		else if (mystr[i] == "*")
		{
			mystr.erase(mystr.begin() + i);
			cout << stoi(mystr[0]) * stoi(mystr[1]);
		}
		else if (mystr[i] == "/")
		{
			mystr.erase(mystr.begin() + i);
			cout << stoi(mystr[0]) / stoi(mystr[1]);
		}
		else if (mystr[i] == "%")
		{
			mystr.erase(mystr.begin() + i);
			cout << stoi(mystr[0]) % stoi(mystr[1]);
		}
	}
}
int main() {
	string str, t;
	getline(cin, str);
	vector<string> mystr;
	stringstream input(str);
	while (input>>t)
	{
		if (t[0] == '-') {
			mystr.push_back(t);
		}
	}
	if (mystr.size()==0)
	{
		cout << "no";
		return 0;
	}
	sort(mystr.begin(), mystr.end());
	mystr.insert(mystr.end(), "b");
	for (unsigned i = 0; i < mystr.size()-1; i++)
	{
		if (mystr[i] != mystr[i + 1]) {
			cout << mystr[i]<<" ";
		}
	}
}*/
int main() {
	double a = 234.43546;
	cout <<setiosflags(ios::fixed)<<setiosflags(ios::left)<<setprecision(2) << setw(8)<<a;
}