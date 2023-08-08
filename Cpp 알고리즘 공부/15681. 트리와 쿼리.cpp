#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int dp[100001];
int U, V;

int dfs(int n) {
	visited[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n][i];
		if (visited[next]) continue;
		dp[n] += dfs(next);
	}
	return dp[n];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> U >> V;
		v[U].push_back(V);
		v[V].push_back(U);
	}

	dp[R] = dfs(R);
	int s;
	for (int i = 0; i < Q; i++) {
		cin >> s;
		cout << dp[s] << '\n';
	}
	return 0;
}