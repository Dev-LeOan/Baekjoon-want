#include <iostream>
#include <queue>
using namespace std;
int MAP[101][101] = { 0 , };
//사과는 1로 표시, 뱀은 2로 표시하기
int dx[4] = { 1, 0, -1, 0 }; //아래, 위
int dy[4] = { 0, 1, 0, -1 }; //오른쪽, 왼쪽
int main() {
	queue <pair<int, int>> Snake; // 뱀의 대가리와 몸통의 길이를 넣어준다.
	queue <pair<int, char>> Direction; // 몇 초(int) 후에 방향(char)을 어디로 돌리는지 넣어준다.
	int N, K; //보드의 크기, 사과의 개수
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int applex, appley; //사과의 x 좌표 y 좌표
		cin >> applex >> appley;
		MAP[applex][appley] = 1; //사과의 위치를 MAP에 입력해주기
	}
	int L;
	cin >> L; // 뱀의 방향 전환 횟수
	for (int i = 0; i < L; i++) {
		int x; char dir; //x는 시간, dir은 방향 정보
		cin >> x >> dir;
		Direction.push(make_pair(x, dir));
	}
	int x = 1, y = 2; //오른쪽으로 시작하므로 미리 y의 값을 올려주었다.
	int dir = 1; // | 0 -> 아래 | 1 -> 오른쪽 | 2 -> 위 | 3 -> 왼쪽 | 시작은 오른쪽이므로 1
	int count = 1; //초 세기

	Snake.push(make_pair(1, 1));
	MAP[1][1] = 2; //뱀의 초기 위치는 1,1이고, 뱀의 위치를 2로 마크

	while (1) {
		if (x > N || y > N || x < 1 || y < 1) { //벽에 부딪히면 break;
			break;
		}
		if (MAP[x][y] == 2) {  //지 몸에 부딪히면 break;
			break;
		}
		if (!Direction.empty()) {
			if (count == Direction.front().first) { //방향 정보 저장된 Direction의 가장 앞에있는 x의 정보가 count와 같을 때 (시작 한 후 x초가 지났을때)
				if (Direction.front().second == 'L') { //방향 정보가 L이라면 dir의 값을 왼쪽으로 90도 돌려야하므로
					dir = (dir + 1) % 4;
				}
				else if (Direction.front().second == 'D') { //방향 정보가 D라면 dir의 값을 오른쪽으로 90도 돌려야하므로
					dir = (dir + 3) % 4;
				}
				Direction.pop();
			}
		}
		if (MAP[x][y] == 0) { //다음 뱀의 위치에 MAP의 저장된 정보가 0이라면 (아무것도 없을 때)
			Snake.push(make_pair(x, y)); //x,y 좌표를 (다음 뱀의 위치를) Snake에 입력
			MAP[Snake.front().first][Snake.front().second] = 0; //큐 맨 앞의 뱀의 위치를 0,0으로 만들어줌 (아무것도 없었으므로) (꼬리가 있다면 끌고 간다)
			Snake.pop(); //현재 뱀 위치를 queue에서 삭제
		}
		else if (MAP[x][y] == 1) { //MAP의 저장된 정보가 1이라면 (사과를 만났을 때)
			Snake.push(make_pair(x, y)); //다음 뱀의 위치를 queue에 넣어준다. (사과를 먹었으므로 현재 뱀의 위치는 그대로 남아있게 된다. 맵과 큐 모두 
		}
		MAP[x][y] = 2; //다음 뱀의 위치를 2로 마크
		x = x + dx[dir]; //아래 위 dir이 0이면 아래 2이면 위
		y = y + dy[dir]; //오른쪽 왼쪽 dir이 1이면 오른쪽 3이면 왼쪽
		count++; //움직인 수만큼 count++
	}
	cout << count;
	return 0;
}