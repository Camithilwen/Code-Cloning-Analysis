#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> R;

const vector<int> dx = { 0, 1, 0, -1 };
const vector<int> dy = { -1, 0, 1, 0 };

int rec(int x, int y)
{
	R[y][x] = '0';

	for (int dir = 0; dir < 4; dir++)
	{
		if (0 <= x + dx[dir] && x + dx[dir] < 12 && 0 <= y + dy[dir] && y + dy[dir] < 12)
		{
			if (R[y + dy[dir]][x + dx[dir]] == '1')
			{
				rec(x + dx[dir], y + dy[dir]);
			}
		}
	}
}

int solve()
{
	int ret = 0;

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (R[i][j] == '1')
			{
				rec(j, i); ret++;
			}
		}
	}

	return ret;
}

int main()
{
	while (true)
	{
		R = vector<string>(12);

		for (int i = 0; i < 12; i++)
		{
			if (!(cin >> R[i]))
			{
				return 0;
			}
		}

		cout << solve() << endl;
	}
}