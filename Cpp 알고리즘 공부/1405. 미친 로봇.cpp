#include <iostream>
using namespace std;

int N;
double percent[4];
double res;
bool visited[29][29];
int dx[] = { -1 , 1 , 0 , 0 }; // ��, ��
int dy[] = { 0 , 0 , -1 , 1 }; // ��, ��
//�������� ���ٸ� -> �������� �� Ȯ�� + ���ʿ��� ��, �� , ���� �� Ȯ��
//����� �������θ� ���� �����ϱ� ù ������ �������� �߿� ���õ� Ȯ��
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
		percent[i] = tmp / 100.0; //�������� ������� �ۼ�Ʈ ����
	}
	dfs(14, 14, 1, 0);
	cout << res;
	return 0;
}