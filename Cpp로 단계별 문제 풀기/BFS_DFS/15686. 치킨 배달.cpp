#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> house, chicken, selected;
bool Select[13];
int result = 9999999;
int Min(int a, int b)
{
	return (a < b) ? a : b;
}
int Find_Min()
{
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int dismin = 9999999;
		int hx = house[i].first;
		int hy = house[i].second;
		for (int j = 0; j < selected.size(); j++)
		{
			int cx = selected[j].first;
			int cy = selected[j].second;
			int dist = abs(cx - hx) + abs(cy - hy);
			dismin = Min(dismin, dist);
		}
		sum += dismin;
	}
	return sum;
}
void Solution(int a, int count)   //조합 활용하기
{
	if (count == M) 
	{
		result = Min(result, Find_Min());
		return;
	}
	for (int i = a; i < chicken.size(); i++)
	{
		if (Select[i] == true)
		{
			continue;
		}
		Select[i] = true;
		selected.push_back(make_pair(chicken[i].first, chicken[i].second));
		Solution(i ,  count + 1);
		Select[i] = false;
		selected.pop_back();
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1) house.push_back(make_pair(i, j));
			if (temp == 2) chicken.push_back(make_pair(i, j));
		}
	}
	Solution(0, 0);
	cout << result << endl;
	return 0;
}