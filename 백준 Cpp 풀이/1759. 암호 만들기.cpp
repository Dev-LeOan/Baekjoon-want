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
	// 모음의 개수가 1개 이상이고, L개 글자 수 - 모음의 개수가 두개 이상 (즉 최소 두개 자음)
	return false;
}
void dfs(int n) {
	if ((int)answer.size() == L) { // 만들어진 answer의 size와 L이 일치하는지
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
		answer.push_back(v[i]); // a c i s 까지 들어간 answer에 문자열이 if('' == L) 걸리고 출력 후 return; 그 후 pop으로 s 빠지고
		// for 문에 의해 그 다음 문자열 t가 push ... 반복
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
