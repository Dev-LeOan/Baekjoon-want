#include <iostream>
using namespace std;
#define MAX 50
int map[MAX][MAX];
int visited[MAX][MAX] = { 0, };
int mx[4] = { -1, 0, 1 , 0 };
int my[4] = { 0, 1, 0, -1 };
int cnt = 1; //û���� ����
int N, M;
int x, y, dir;
void cleaner()   // dir = | 0 �� | 1 �� | 2 �� | 3 ��
{
	for (int i = 0; i < 4; i++)
	{
		int next_dir = (dir + 3 - i) % 4; //�ݽð� ���� 90���� �������� ���°�
		int next_x = x + mx[next_dir];
		int next_y = y + my[next_dir];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || map[next_x][next_y] == 1) {
			continue;
		}
		if (map[next_x][next_y] == 0 && visited[next_x][next_y] == 0)  //���ƺ� ���⿡ û������ ���� ���� ����
		{
			visited[next_x][next_y] = 1;
			cnt++;
			x = next_x;
			y = next_y;
			dir = next_dir;
			cleaner();
		}
	}
	//for���� ����� �� = ���ƺ� ���⿡ û������ ���� ������ �������� ���� ��,
	int back_index = dir > 1 ? dir - 2 : dir + 2; //�ٶ� ���� ���� ��ĭ �ڷ� �̵� (���� �ٶ󺸰� ������ ���� �� ĭ �̵�)
	int back_x = x + mx[back_index];
	int back_y = y + my[back_index];
	if (back_x >= 0 && back_x <= N || back_y >= 0 || back_y <= M) //���� �ƴ� ��
	{
		if (map[back_x][back_y] == 0)
		{
			x = back_x;
			y = back_y;
			cleaner();
		}
		else
		{
			cout << cnt << endl;
			exit(0);
		}
	}
}

int main()
{
	cin >> N >> M;
	cin >> x >> y >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			cin >> map[i][j];
		}
	}
	visited[x][y] = 1;
	cleaner();
	return 0;
}