#include <iostream>
//���� ������ Ȱ���Ͽ� Ǯ����ϴ� ����
#include <vector>
#define ll long long
using namespace std;
int CCW(pair<ll, ll> A, pair <ll,ll> B, pair<ll,ll> C)
{
	ll temp = A.first * B.second + B.first * C.second + C.first * A.second;
	temp = temp - A.second * B.first - B.second * C.first - C.second * A.first;
	if (temp > 0) return 1; // �ݽð�
	else if (temp == 0) return 0; // ������
	else if (temp < 0) return -1; // �ð�
}
bool overlap(pair<ll, ll> A, pair <ll, ll> B, pair<ll, ll> C, pair<ll, ll> D)
{
	int r1 = CCW(A, B, C) * CCW(A, B, D);
	int r2 = CCW(C, D, A) * CCW(C, D, B);
	if (r1 == 0 && r2 == 0)
	{
		if (A > B)swap(A, B);
		if (C > D) swap(C, D);
		if (A <= D && C <= B) // �� �� ��� ������ �� ���� ��
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (r1 <= 0 && r2 <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	pair<int, int> A; 
	pair<int, int> B;

	pair<int, int> C; 
	pair<int, int> D;

	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	cin >> D.first >> D.second;

	if (overlap(A, B, C, D))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
}