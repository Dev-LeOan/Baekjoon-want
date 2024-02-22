#include <iostream>
#include <algorithm>
using namespace std;
char map[50][50];
char chess[8][8];
int mina = 50;
char white_arr[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};
char black_arr[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B'
};
int fill()
{
	int count_white = 0;
	int count_black = 0;
	if (chess[0][0] == 'W')
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (chess[i][j] != white_arr[i][j])
				{
					count_white++;
				}
				if (chess[i][j] != black_arr[i][j])
				{
					count_black++;
				}
			}
		}
	}
	if (chess[0][0] == 'B')
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (chess[i][j] != white_arr[i][j])
				{
					count_white++;
				}
				if (chess[i][j] != black_arr[i][j])
				{
					count_black++;
				}
			}
		}
	}
	return min(count_white,count_black);
}
int cut(int nstart , int mstart)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			chess[i][j] = ' ';
		}
	}
	for (int i = 0; i < 8; i++ )
	{
		for (int j = 0; j < 8; j++)
		{
			chess[i][j] = map[i+nstart][j+mstart];
		}
	}
	int result = fill();
	return result;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= n-8; i++)
	{
		for (int j = 0; j <= m-8; j++)
		{
			int m = cut(i , j);
			if (m < mina)
			{
				mina = m;
			}
		}
	}
	cout << mina << endl;
}