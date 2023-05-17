#include <iostream>
using namespace std;
int main()
{
	int arr1[3];
	int arr2[3];
	int a, b;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		arr1[i] = a;
		arr2[i] = b;
	}
	int x, y;
	if (arr1[0] == arr1[1]) {
		x = arr1[2];
	}
	else if (arr1[1] == arr1[2]) {
		x = arr1[0];
	}
	else if (arr1[0] == arr1[2]) {
		x = arr1[1];
	}
	if (arr2[0] == arr2[1]) {
		y = arr2[2];
	}
	else if (arr2[1] == arr2[2]) {
		y = arr2[0];
	}
	else if (arr2[0] == arr2[2]) {
		y = arr2[1];
	}
	cout << x << " " << y << endl;
}