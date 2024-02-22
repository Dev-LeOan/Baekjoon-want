#include <iostream>
using namespace std;
int arr[100000];
void order(int start, int end)
{
	if (start >= end)
	{
		return;
	}
	if (start == end - 1)
	{
		cout << arr[start] << '\n';
		return;
	}
	int idx = start + 1;
	while (idx < end)
	{
		if (arr[start] < arr[idx])
		{
			break;
		}
		idx++;
	}
	order(start + 1, idx);
	order(idx, end);
	cout << arr[start] << '\n';
}
int main()
{
	int num;
	int index = 0;
	while (cin >> num)
	{
		arr[index++] = num;
	}
	order(0, index);
	return 0;
}