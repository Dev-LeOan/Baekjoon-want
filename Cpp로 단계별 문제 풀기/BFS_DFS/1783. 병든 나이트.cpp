#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if (n == 1)
	{
		cout << 1;
	}
	else if (n == 2)
	{
		cout << min(4, (m - 1) / 2 + 1); // 1�϶� 1, 2�϶� 1, 3�϶� 2, 4�϶� 2, 5�϶� 3
	}
	else //n >= 3
	{
		if (m < 7)
		{
			cout << min(4 , m); //1�̸� 1, 2�̸� 2, 3�̸� 3, 4�� 
		}
		else
		{
			cout << m - 2; 
		}
	}
}