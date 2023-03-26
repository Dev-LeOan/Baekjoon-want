#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k;
	int count = 0;
	cin >> n >> k;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			
			arr[count] = i;
			count++;
		}
	}
	if (arr[k - 1] != -1) {
		cout << arr[k-1] << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}
