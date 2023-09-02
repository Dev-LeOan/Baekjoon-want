#include <iostream>
using namespace std;
bool broken_button[10]; //���峭 ��ư ����
int can_push(int n) { 
	if (n == 0) { // 0�� ä�η� �̵�������
		if (broken_button[n]) { //���峵����
			return 0;
		}
		else {
			return 1;
		}
	}
	int tmp = 0;
	while (n > 0) { //���� ������ ��ư�� ���������� Ȯ���ϱ�, n�� 0���� ū ���� 10���� ��� ������ ��ư�� ���������� Ȯ��
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
	cin >> target;  //��ǥ ä��
	int broken_button_number;
	cin >> broken_button_number;  //���峭 ��ư ����
	if (broken_button_number > 0) {
		for (int i = 0; i < broken_button_number; i++) {
			int number;
			cin >> number; //���峭 ��ư ��ȣ
			broken_button[number] = true; //���峭 ��ư �������� ���
		}
	}
	int answer = abs(target - 100); //100������ �����̹Ƿ� 100������ ������ �����̱� ������ ���� (100�� ä�ΰ� ��ǥ ���� ä�� �� ����)
	for (int i = 0; i <= 1000000; i++) {
		int channel = i;
		int len = can_push(channel); //i = 0�� ä���� ���� 0�̳� 1�� ��ȯ�ǰ�, i > 1���ʹ� tmp�� ����� ���� len�� ����.
		if (len > 0) { // len���� tmp�� ����� ���� ����ִ�. (���� ��ư ���� Ƚ��)
			int press = abs(channel - target); //���� i�������� target������ �̵� Ƚ�� = press
			if (answer > len + press) { //���� ��ư ���� Ƚ�� + target������ �̵� Ƚ��
				answer = len + press;
			}
		}
	}
	cout << answer;
	return 0;
}