#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int N, K;
	int count =0;
	string num;
	cin >> N >> K;
	cin >> num;
	stack<char> result_stack;
	stack<char> reverse_stack;
	for (int i = 0; i < num.size(); i++) {										    //stack�� ������� �ʴ�.
		while (!result_stack.empty() && count < K && num[i] > result_stack.top()) { //���� Ƚ�� count�� �ִ� �� �� �ִ� Ƚ�� K���� �۾ƾ��Ѵ�.
			count++;// ���� Ƚ�� ++													//���� ������ ���� ���� �ִ� ���� num���� ���� ��
			result_stack.pop();														//(�տ� ���� ū ���� �־�� ��.
		}	//���� ���� �ִ� ���� ���ش� (������ ��� �� ���� �� ũ�� ������
		result_stack.push(num[i]); 
	}
	while (count < K) { //���� �ѹ��� pop�� �̷������ ���� ��찡 ����ٸ� count���� ��� �ø����� �Ѵ�. (3 2 1 ���� ��쿡)
		count++;
		result_stack.pop();  //���� �ֱٿ� ���� �ͺ��� ������ pop();
	}

	while (!result_stack.empty())
	{
		reverse_stack.push(result_stack.top());
		result_stack.pop(); //���� ����ֱ�
	}
	while (!reverse_stack.empty())
	{
		cout << reverse_stack.top(); //�ݴ�� ���� ��� �����ֱ�
		reverse_stack.pop(); //���� ����ֱ�
	}
	return 0;
}