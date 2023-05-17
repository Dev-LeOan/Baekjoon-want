//https://www.acmicpc.net/problem/2444
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int j = 1; j < n + 1; j++)
	{
		for (int i = 0; i < n - j; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 2*j - 1; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int j = n-1; j > 0; j--)
	{
		for (int i = 1; i < n - j + 1; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 2*j - 1; i++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}
