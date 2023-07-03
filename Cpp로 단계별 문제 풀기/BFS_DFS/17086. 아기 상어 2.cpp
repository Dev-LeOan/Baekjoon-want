#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int map[50][50];
bool visit[50][50];
int n, m;
int temp, result;
int dx[8] = { 1 , -1 , 0 , 0 , 1 , 1 , -1 , -1 };
int dy[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 };
typedef struct box
{
	int x;
	int y;
	int r;
};
int BFS(int a, int b)
{
	fill(&visit[0][0], &visit[49][49], false);
	queue<box> q;
	visit[a][b] = true;
	q.push({ a , b , 0 });
	while (!q.empty())
	{
		int qx = q.front().x;
		int qy = q.front().y;
		int qr = q.front().r;

		q.pop();	

		for (int i = 0; i < 8; i++)	
		{
			int qxx = qx + dx[i];
			int qyy = qy + dy[i];

			if (qxx < 0 || qyy < 0 || qxx >= n || qyy >= m)continue;	
			if (visit[qxx][qyy] == true)continue;	

			if (map[qxx][qyy] == 1)	
				return qr + 1;

			visit[qxx][qyy] = true;	
			q.push({ qxx,qyy,qr + 1 });	
		}
	}
	return 0;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				temp = BFS(i, j);
				result = max(result, temp);
			}
		}
	}
	cout << result;
	return 0;
}