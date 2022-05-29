#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool f(string s)
{
	stack<char> mystack;
	for (int i = 0; i < s.length(); i++){
		switch (s[i])
		{
		case '(':
			mystack.push(s[i]);
			break;
		case '[':
			mystack.push(s[i]);
			break;
		case '{':
			mystack.push(s[i]);
			break;
		case ')':
			if (mystack.empty()){  //ÅÐ¶Ï¶àÁËÓÒÀ¨ºÅ
				return false;
			}
			if (mystack.top()=='('){
				mystack.pop();
			}
			else{
				return false;
			}
			break;
		case ']':
			if (mystack.empty()){  //ÅÐ¶Ï¶àÁËÓÒÀ¨ºÅ
				return false;
			}
			if (mystack.top() == '['){
				mystack.pop();
			}
			else{
				return false;
			}
			break;
		case '}':
			if (mystack.empty()){  //ÅÐ¶Ï¶àÁËÓÒÀ¨ºÅ
				return false;
			}
			if (mystack.top() == '{'){
				mystack.pop();
			}
			else{
				return false;
			}
			break;
		default:
			break;
		}
	}
	return mystack.empty();    //ÅÐ¶Ï¶àÁË×óÀ¨ºÅ
}
int main()
{
	string str;
	cin >> str;
	if (f(str))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
}