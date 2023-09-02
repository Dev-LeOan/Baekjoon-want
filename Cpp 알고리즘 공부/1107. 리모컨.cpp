#include <iostream>
using namespace std;
bool broken_button[10]; //고장난 버튼 모음
int can_push(int n) { 
	if (n == 0) { // 0번 채널로 이동했을때
		if (broken_button[n]) { //고장났으면
			return 0;
		}
		else {
			return 1;
		}
	}
	int tmp = 0;
	while (n > 0) { //현재 수에서 버튼이 눌러지는지 확인하기, n이 0보다 큰 동안 10으로 계속 나누며 버튼이 눌러지는지 확인
		if (broken_button[n % 10]) {
			return 0;
		}
		tmp += 1;
		n /= 10;
	}
	return tmp;
}
int main() {
	int target;
	cin >> target;  //목표 채널
	int broken_button_number;
	cin >> broken_button_number;  //고장난 버튼 개수
	if (broken_button_number > 0) {
		for (int i = 0; i < broken_button_number; i++) {
			int number;
			cin >> number; //고장난 버튼 번호
			broken_button[number] = true; //고장난 버튼 모음집에 담기
		}
	}
	int answer = abs(target - 100); //100번부터 시작이므로 100번보다 작으면 음수이기 때문에 절댓값 (100번 채널과 목표 값의 채널 수 차이)
	for (int i = 0; i <= 1000000; i++) {
		int channel = i;
		int len = can_push(channel); //i = 0번 채널일 때는 0이나 1이 반환되고, i > 1부터는 tmp에 저장된 값이 len에 들어간다.
		if (len > 0) { // len에는 tmp에 저장된 값이 들어있다. (숫자 버튼 누른 횟수)
			int press = abs(channel - target); //현재 i에서부터 target까지의 이동 횟수 = press
			if (answer > len + press) { //숫자 버튼 누른 횟수 + target까지의 이동 횟수
				answer = len + press;
			}
		}
	}
	cout << answer;
	return 0;
}