#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[1001];
int dp1[1001];
int dp2[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {cin >> A[i];}
	fill_n(dp1, 1001, 1); //�� dp�� ���� ��� 1�� ������ش�. (fill�Լ�)
	fill_n(dp2, 1001, 1);

	for (int i = 1; i <= N; i++) {   //������ �˻�
		for (int j = 1; j <= i; j++) {
			if (A[j] < A[i] && dp1[i] < dp1[j]+1) {
				dp1[i] = dp1[j] + 1;
			}
		}
	}
	for (int i = N; i >= 1; i--) { //�������� �˻�
		for (int j = N; j >= i; j--) {
			if (A[j] < A[i] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;	
			}
		}
	}
	int m = 0;
	for (int i = 0; i <= N; i++) {
		m = max(m, (dp1[i] + dp2[i])); // ���� i�� ���Ͽ� ���� ������ ��ģ�� ���� Ŭ ���� ���Ѵ�.
	}
	cout << m - 1 << endl;

}