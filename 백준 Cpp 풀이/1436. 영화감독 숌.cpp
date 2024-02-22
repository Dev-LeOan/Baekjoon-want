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
			if (to_string(s).find("666") != string::npos) //666이 있으면 count를 증가시켜라.
			{
				count++;
			}
		}
		cout << s;
	}
}