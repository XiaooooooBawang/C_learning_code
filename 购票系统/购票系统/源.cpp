#include<iostream>
using namespace std;
int seat[20][5];
int get_row_empty(int row)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (seat[row][i] == 0)
		{
			count++;
		}
	}
	return count;
}
int book(int row,int num)
{
	int head;
	for (int i = 0; i < 5; i++)
	{
		if (seat[row][i] == 0)
		{
			head = i;
			for (int j = i; j < num+i; j++)
			{
				seat[row][j] = 1;
			}
			break;
		}
	}
	return head;
}
int main()
{
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		int book_row,head,flag=0;
		for (int j = 0; j < 20; j++)
		{
			if (get_row_empty(j)>=a)
			{
				flag = 1;
				head = book(j, a);
				book_row=j;
				break;
			}
		}
		if (flag)
		{
			for (int k = 0; k < a; k++)
			{
				if (k == a - 1)
				{
					cout << book_row * 5 + head + 1+k << "\n";
				}
				else
				{
					cout << book_row * 5 + head + 1+k << " ";
				}
			}
		}
		else
		{
			for (int j = 0; j < 20; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (seat[j][k] == 0&&a>0)
					{
						if (a==1)
						{
							cout << j * 5 + k + 1 << "\n";
						}
						else
						{
							cout << j * 5 + k + 1 << " ";
						}
						a--;
						seat[j][k] = 1;
					}
				}
			}
		}
	}
}