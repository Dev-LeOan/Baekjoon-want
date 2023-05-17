#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[16] = { 0, };
	arr[0] = 4;
	int n, a;
	cin >> n;
	// n 0Àº 4 /  1Àº 9 / 2´Â 25
	for (int i = 1; i < n+1; i++)
	{	
		arr[i] = (sqrt(arr[i - 1]) * 2 - 1) * (sqrt(arr[i - 1]) * 2 - 1);
	}
	cout << arr[n];
	return 0;
}