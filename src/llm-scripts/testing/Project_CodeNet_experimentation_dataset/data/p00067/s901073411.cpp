#include <iostream>
using namespace std;
char m[12][13];
void dfs(int x, int y)
{
	int i, j, nx, ny;
	m[y][x] = '0';
	for (i = 1; i >= -1; i--)
	{
		if (i == 1 || i == -1)
		{
			nx = x;
			ny = y + i;
			if (0 <= nx && nx < 12 && 0 <= ny && ny < 12 && m[ny][nx] == '1') dfs(nx, ny);
		}
		else
		{
			for (j = 1; j >= -1; j--)
			{
				nx = x + j;
				ny = y + i;
				if (0 <= nx && nx < 12 && 0 <= ny && ny < 12 && m[ny][nx] == '1') dfs(nx, ny);
			}
		}
	}
	return;
}
int main()
{
	int i, j, n;
	while (1)
	{
		for (i = 0; i < 12; i++)
		{
			cin >> m[i];
			if (cin.eof()) return 0;
		}
		n = 0;
		for (i = 0; i < 12; i++)
		{
			for (j = 0; j < 12; j++)
			{
				if (m[i][j] == '1')
				{
					n++;
					dfs(j, i);
				}
			}
		}
		cout << n << endl;
	}
}