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
		cout << min(4, (m - 1) / 2 + 1); // 1일때 1, 2일때 1, 3일때 2, 4일때 2, 5일때 3
	}
	else //n >= 3
	{
		if (m < 7)
		{
			cout << min(4 , m); //1이면 1, 2이면 2, 3이면 3, 4면 
		}
		else
		{
			cout << m - 2; 
		}
	}
}