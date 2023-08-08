#include <iostream>
using namespace std;

int N;
double percent[4];
double res;
bool visited[29][29];
int dx[] = { -1 , 1 , 0 , 0 }; // 남, 북
int dy[] = { 0 , 0 , -1 , 1 }; // 동, 서
//동쪽으로 갔다면 -> 동쪽으로 갈 확률 + 동쪽에서 북, 남 , 서로 갈 확률
//출발을 동쪽으로만 가지 않으니까 첫 방향이 동서남북 중에 선택될 확률
void dfs(int x , int y, double sum_avg, int cnt)
{
	if (visited[y][x]) {
		return;
	}
	visited[y][x] = true;
	
	if (cnt == N) {
		res += sum_avg;1
		visited[y][x] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny, sum_avg * percent[i], cnt + 1);
	}
	visited[y][x] = false;
}
int main()
{
	cout << fixed;
	cout.precision(18);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		double tmp; 
		cin >> tmp;
		percent[i] = tmp / 100.0; //동서남북 순서대로 퍼센트 저장
	}
	dfs(14, 14, 1, 0);
	cout << res;
	return 0;
}