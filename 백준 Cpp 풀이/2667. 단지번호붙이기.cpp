#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 25;
int N;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int label = 1;
vector<int> v;
int house = 0;

void solution(int y, int x) {
    visited[y][x] = true;
    map[y][x] = label;
    house++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            solution(ny, nx);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            map[i][j] = s.at(j) - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                solution(i, j);
                label++;
                v.push_back(house);
                house = 0;
            }
        }
    }

    sort(v.begin(), v.end());

    cout << label - 1 << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

}
