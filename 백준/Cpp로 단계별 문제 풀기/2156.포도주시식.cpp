#include <iostream>
using namespace std;
int n;
int a[10001];
int b[10001];
//각 잔의 양과 n 번째까지의 잔의 양을 더했을 때 만들어진 최대 양
int max(int a, int b) { if (a > b) return a; return b; }
void DP()
{
	b[0] = a[0] = 0;  //0번째 까지 마신 양
	b[1] = a[1];      //1번째 까지 마신 양
	b[2] = a[1] + a[2]; //2번째 까지 마신 양
	// 1 2 3
	// 1 2 3 4        (1,2,4) (1,3,4) (2,3)
	// 1 2 3 4 5 6
	// 3번 연속 못 마시므로, 3번째 부터는 1, 2 또는 2, 3 또는 1, 3으로 계산해야한다. 
	// n개라고 치면, (n-3번째까지 마신 최대 양 + N-1 + N), (n-2번째까지 마신 최대 양 + N), (n-1번째까지 마신 최대 양) 중 가장 큰 것을 비교해야한다. 
	for (int i = 3; i <= n; i++)
	{
		b[i] = max(b[i - 3] + a[i - 1] + a[i], max(b[i - 2] + a[i], b[i - 1]));
	}
}
int main()
{
	cin >> n;   //잔의 개수
	
	for (int i = 1; i <= n; i++)
	{	
		cin >> a[i];
	}
	DP();
	cout << b[n] << endl;

}