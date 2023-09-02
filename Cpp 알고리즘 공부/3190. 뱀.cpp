#include <iostream>
#include <queue>
using namespace std;
int MAP[101][101] = { 0 , };
//����� 1�� ǥ��, ���� 2�� ǥ���ϱ�
int dx[4] = { 1, 0, -1, 0 }; //�Ʒ�, ��
int dy[4] = { 0, 1, 0, -1 }; //������, ����
int main() {
	queue <pair<int, int>> Snake; // ���� �밡���� ������ ���̸� �־��ش�.
	queue <pair<int, char>> Direction; // �� ��(int) �Ŀ� ����(char)�� ���� �������� �־��ش�.
	int N, K; //������ ũ��, ����� ����
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int applex, appley; //����� x ��ǥ y ��ǥ
		cin >> applex >> appley;
		MAP[applex][appley] = 1; //����� ��ġ�� MAP�� �Է����ֱ�
	}
	int L;
	cin >> L; // ���� ���� ��ȯ Ƚ��
	for (int i = 0; i < L; i++) {
		int x; char dir; //x�� �ð�, dir�� ���� ����
		cin >> x >> dir;
		Direction.push(make_pair(x, dir));
	}
	int x = 1, y = 2; //���������� �����ϹǷ� �̸� y�� ���� �÷��־���.
	int dir = 1; // | 0 -> �Ʒ� | 1 -> ������ | 2 -> �� | 3 -> ���� | ������ �������̹Ƿ� 1
	int count = 1; //�� ����

	Snake.push(make_pair(1, 1));
	MAP[1][1] = 2; //���� �ʱ� ��ġ�� 1,1�̰�, ���� ��ġ�� 2�� ��ũ

	while (1) {
		if (x > N || y > N || x < 1 || y < 1) { //���� �ε����� break;
			break;
		}
		if (MAP[x][y] == 2) {  //�� ���� �ε����� break;
			break;
		}
		if (!Direction.empty()) {
			if (count == Direction.front().first) { //���� ���� ����� Direction�� ���� �տ��ִ� x�� ������ count�� ���� �� (���� �� �� x�ʰ� ��������)
				if (Direction.front().second == 'L') { //���� ������ L�̶�� dir�� ���� �������� 90�� �������ϹǷ�
					dir = (dir + 1) % 4;
				}
				else if (Direction.front().second == 'D') { //���� ������ D��� dir�� ���� ���������� 90�� �������ϹǷ�
					dir = (dir + 3) % 4;
				}
				Direction.pop();
			}
		}
		if (MAP[x][y] == 0) { //���� ���� ��ġ�� MAP�� ����� ������ 0�̶�� (�ƹ��͵� ���� ��)
			Snake.push(make_pair(x, y)); //x,y ��ǥ�� (���� ���� ��ġ��) Snake�� �Է�
			MAP[Snake.front().first][Snake.front().second] = 0; //ť �� ���� ���� ��ġ�� 0,0���� ������� (�ƹ��͵� �������Ƿ�) (������ �ִٸ� ���� ����)
			Snake.pop(); //���� �� ��ġ�� queue���� ����
		}
		else if (MAP[x][y] == 1) { //MAP�� ����� ������ 1�̶�� (����� ������ ��)
			Snake.push(make_pair(x, y)); //���� ���� ��ġ�� queue�� �־��ش�. (����� �Ծ����Ƿ� ���� ���� ��ġ�� �״�� �����ְ� �ȴ�. �ʰ� ť ��� 
		}
		MAP[x][y] = 2; //���� ���� ��ġ�� 2�� ��ũ
		x = x + dx[dir]; //�Ʒ� �� dir�� 0�̸� �Ʒ� 2�̸� ��
		y = y + dy[dir]; //������ ���� dir�� 1�̸� ������ 3�̸� ����
		count++; //������ ����ŭ count++
	}
	cout << count;
	return 0;
}