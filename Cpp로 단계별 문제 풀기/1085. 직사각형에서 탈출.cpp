#include <iostream>
using namespace std;
int main()
{
	int x, y, w, h = 0;
	cin >> x >> y >> w >> h;
	int min = 1000;
	if (w - x < x) {
		min = w - x;
	}
	else {
		min = x;
	}
	if (h - y < y && h-y < min) {
		min = h - y;
	}
	else if (y < min){
		min = y;
	}

	cout << min;
	
}
