#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int a = N - 1;
	if (a == 0)
	{
		cout << "666";
	}
	else
	{
		int s = 666;
		int count = 0;
		while (count != a)
		{
			s++;
			if (to_string(s).find("666") != string::npos) //666�� ������ count�� �������Ѷ�.
			{
				count++;
			}
		}
		cout << s;
	}
}