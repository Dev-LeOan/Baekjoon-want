#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
// �ð�, ��ġ // ���� ���� �켱���� Ž���Ǿ�����. ����ġ 0�� *2�� ���� ���� �����

void BFS(int N, int K)
{
	q.push({ 0, N }); //����ġ 0 , ��ġ N
	visited[N] = true;  //��ġ N �湮 ǥ��
	while (!q.empty())
	{
		int time = q.top().first;
		int point = q.top().second;
		q.pop();

		if (point == K)
		{
			cout << time;
			return ;
		}
		for (int dir = 0; dir < 3; dir++)
		{
			int nx = 0;
			if (dir == 0)
			{
				nx = point * 2;
			}
			else if (dir == 1)
			{
				nx = point + 1;
			}
			else if (dir == 2)
			{
				nx = point - 1;
			}
			if (nx < 0 || nx > 100000) continue;	
			if (visited[nx] == true) continue;
			if (dir == 0)
			{
				q.push({time, nx});
				visited[nx] = true;
			}
			else
			{
				q.push({ time + 1, nx });  // ����ġ 1
				visited[nx] = true;
			}
		}
	}
}
int main()
{
	int N, K;
	cin >> N >> K;
	BFS(N, K);
	return 0;
}