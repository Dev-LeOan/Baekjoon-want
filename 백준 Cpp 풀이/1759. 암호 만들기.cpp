#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
int L, C;
vector<char> v;
vector<char> answer;

bool check_is_true() {
	int mo = 0;
	for (int i = 0; i < L; i++)
	{
		if (answer[i] == 'a' ||
			answer[i] == 'e' ||
			answer[i] == 'i' ||
			answer[i] == 'o' ||
			answer[i] == 'u')
			mo++;
	}
	if (mo >= 1 && L - mo >= 2) return true; 
	// ������ ������ 1�� �̻��̰�, L�� ���� �� - ������ ������ �ΰ� �̻� (�� �ּ� �ΰ� ����)
	return false;
}
void dfs(int n) {
	if ((int)answer.size() == L) { // ������� answer�� size�� L�� ��ġ�ϴ���
		if (check_is_true()) {
			for (int k = 0; k < L; k++)
			{
				cout << answer[k];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = n; i < C; i++)
	{
		answer.push_back(v[i]); // a c i s ���� �� answer�� ���ڿ��� if('' == L) �ɸ��� ��� �� return; �� �� pop���� s ������
		// for ���� ���� �� ���� ���ڿ� t�� push ... �ݺ�
		dfs(i + 1);
		answer.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	dfs(0);
}
