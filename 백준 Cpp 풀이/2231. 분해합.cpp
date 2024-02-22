#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int result = 0;
	for (int i = 0; i < a; i++)
	{
		int sum = 0;
		int number = i;
		while (number != 0)
		{
			sum += number % 10;
			number /= 10;
		}
		if ((sum + i) == a)
		{
			result = i;
			break;
		}
	}
	cout << result << endl;
}