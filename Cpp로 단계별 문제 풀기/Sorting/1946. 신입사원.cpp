#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T, N;  //테스트 횟수 N, 지원자의 숫자 N
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		vector<pair<int, int>> v;
		for (int j = 0; j < N; j++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(v.begin(), v.end());
		int count = 1;
		int tmp = 0;
		for (int j = 1; j < N; j++)
		{
			if (v[tmp].second > v[j].second)
			{
				count++;
				tmp = j;
			}
		}
		cout << count << endl;
	}
}