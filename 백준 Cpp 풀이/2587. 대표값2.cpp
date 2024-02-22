#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int avg = sum / 5;
	cout << avg << endl;
	sort(a, a + 5);
	cout << a[2] << endl;
}