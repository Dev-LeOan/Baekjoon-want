#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b)
{
	return a > b;
}
int main()
{
	string arr[9];
	string answer;
	cin >> answer;
	int gh = answer.length();
	for (int i = 0; i < gh; i++)
	{
		arr[i] = answer.substr(i, 1);
	}
	sort(arr, arr + gh,compare);
	
	for (int i = 0; i < gh; i++)
	{
		cout << arr[i];
	}
	return 0;
}