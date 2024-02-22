#include <iostream>
#define MAX 501
using namespace std;
int N, M;
int Map[MAX][MAX] = { 0, };
int visited[MAX][MAX] = { 0, };
int dp[MAX][MAX] = { 0, };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int DFS(int x, int y)
{
	if (x == N-1 && y == M-1)
	{
		return 1;
	}
	if (visited[x][y] == 1)
	{
		return dp[x][y];
	}
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && mx < N && my >= 0 && my < M)  // �ε��� ���� Map �ȿ� ���� ��
		{
			if (Map[x][y] > Map[mx][my]) // �ڽ��� �ε����� ũ�⺸�� ���� ��
			{
				dp[x][y] += DFS(mx, my); //�̵��� ��ǥ���� �ٽ� Ž��
			}
		}
	}
	return dp[x][y];
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{			
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	cout << DFS(0, 0) << endl;
	return 0;
}