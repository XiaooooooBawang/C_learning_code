#include<iostream>
#include<algorithm>
int a[100010];
int main()
{
	int n;
	long long int sum=0;
	std::cin >> n;
	//std::cin >> sum;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	std::sort(a,a+n);
	for (int i = 0; i < n; i++)
	{
		sum +=((2 * (i+1) - n - 1) * a[i]);
	}
	std::cout << sum % 998244353;
}