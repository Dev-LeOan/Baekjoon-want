#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
int maxx = 0;
long long sum;
vector<int> v;
int answer;

int main() {
    cin >> N >> M;
    for (auto i = 0; i < N; i++) {
        int b;
        cin >> b;
        v.push_back(b);
        if (b >= maxx)
        {
            maxx = b;
        }
    }

    int left = 0;
    int right = maxx;

    while (left <= right) {
        int cutter = (left + right) / 2;
        sum = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] > cutter) { sum += v[i] - cutter; }
        }
        if (sum >= M) {
            if (answer < cutter)
            {
                answer = cutter;
            }
            left = cutter + 1;
        }
        else {
            right = cutter - 1;
        }
    }
    cout << answer;
}