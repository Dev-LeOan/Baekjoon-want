#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MAX 101
//단지 번호 붙이기를 활용
int N, M;
int visited[MAX][MAX] = { 0 ,};
int dist[MAX][MAX] = { 0, };
int miro[MAX][MAX] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
void BFS(int stx, int sty)
{
	visited[stx][sty] = 1;
	q.push(make_pair(stx, sty));
	dist[stx][sty] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int mx = x + dx[i];
			int my = y + dy[i];

			if ((0 <= mx && mx < N) && (0 <= my && my < M) && !visited[mx][my] && miro[mx][my] == 1) //갈 수 있어야하고 (1), 방문했던 곳이 아니어야함
			{
				visited[mx][my] = 1;
				q.push(make_pair(mx, my));
				dist[mx][my] = dist[x][y] + 1;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			miro[i][j] = row[j] - '0';
		}
	}
	BFS(0, 0);
	cout << dist[N - 1][M - 1];
}