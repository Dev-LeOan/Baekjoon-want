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
	for (int i = 0; i < num.size(); i++) {										    //stack이 비어있지 않다.
		while (!result_stack.empty() && count < K && num[i] > result_stack.top()) { //빼낸 횟수 count가 최대 뺄 수 있는 횟수 K보다 작아야한다.
			count++;// 빼낸 횟수 ++													//현재 스택의 가장 위에 있는 수가 num보다 작을 때
			result_stack.pop();														//(앞에 가장 큰 수가 있어야 함.
		}	//제일 위에 있던 수는 빼준다 (다음에 들어 올 수가 더 크기 때문에
		result_stack.push(num[i]); 
	}
	while (count < K) { //만약 한번도 pop이 이루어지지 않은 경우가 생긴다면 count값을 계속 올리도록 한다. (3 2 1 같은 경우에)
		count++;
		result_stack.pop();  //가장 최근에 들어온 것부터 모조리 pop();
	}

	while (!result_stack.empty())
	{
		reverse_stack.push(result_stack.top());
		result_stack.pop(); //스택 비워주기
	}
	while (!reverse_stack.empty())
	{
		cout << reverse_stack.top(); //반대로 만들어서 출력 시켜주기
		reverse_stack.pop(); //스택 비워주기
	}
	return 0;
}