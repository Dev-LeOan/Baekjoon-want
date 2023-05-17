#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> list;
int main() {
    int N, temp, range, mid = 0, many, avg = 0;
    int count = -9999;
    int number[8001] = { 0, };
    bool first = false;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        list.push_back(temp);
        avg += temp;
        number[temp + 4000]++;
    }

    sort(list.begin(), list.end());

    for (int i = 0; i < 8001; i++)
    {
        if (number[i] == 0)
            continue;
        if (number[i] == count)
        {
            if (first)
            {
                many = i - 4000;
                first = false;
            }
        }
        if (number[i] > count)
        {
            count = number[i];
            many = i - 4000;
            first = true;
        }
    }
    avg = round((float)avg / N);
    mid = list[list.size() / 2];
    range = list.back() - list.front();
    cout << avg << '\n' << mid << '\n' << many << '\n' << range;

}
