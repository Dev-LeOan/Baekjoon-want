#include <iostream>
#include <string>
#define max 9
using namespace std;
int map[max][max];
bool row[max][max];
bool col[max][max];
bool square[max][max];
void dfs(int count)
{
    int x = count / max;
    int y = count % max;
    if (count == 81)
    {
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        }
        exit(0);
    }
    if (map[x][y] == 0) 
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
            {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                map[x][y] = i;
                dfs(count + 1);
                map[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
    else dfs(count + 1);
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        string stringtemp;
        cin >> stringtemp;
        for (int j = 0; j < stringtemp.length(); j++)
        {
            map[i][j] = stringtemp[j] - '0';
            if (map[i][j] != 0)
            {
                row[i][map[i][j]] = true;  // i행에 map[i][j]의 숫자가 존재한다.
                col[j][map[i][j]] = true;  // j열에 map[i][j]의 숫자가 존재한다.
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = true; // (i/3)*3+(j/3) 사각형에 map[i][j]의 숫자가 존재한다.
            }
        }
    }
    dfs(0);
}