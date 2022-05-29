#include<iostream>
using namespace std;
int a[150];
int main()
{
	int t,n, m;
	cin >>t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >>a[j];
			sum += a[j];
		}
		if (m <= 1)
		{
			cout << "0\n" << endl;
		}
		else if (m > 1 && m <= n)
		{
			
		}
		else if (m > n)
		{
			int pay = 0;
			for (int k = 0; k < n; k++)
			{
				pay += sum - a[k];
			}
			cout << pay*(m-n) << "\n" << endl;
		}

		
	}
}