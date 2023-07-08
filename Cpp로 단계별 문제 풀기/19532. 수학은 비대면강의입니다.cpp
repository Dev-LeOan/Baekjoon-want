#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	int rx=0, ry=0;
	cin >> a >> b >> c >> d >> e >> f;
	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if (((a * x) + (b * y) == c) && ((d * x) + (e * y) == f))
			{
				rx = x;
				ry = y;
				break;
			}
		}
	}
	cout << rx << " " << ry << endl;
	return 0;
}