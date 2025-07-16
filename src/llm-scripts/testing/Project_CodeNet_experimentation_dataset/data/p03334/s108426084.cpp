#include<bits/stdc++.h>
#define pf(x) x*x
using namespace std;
int n, d[2], col[2][360007];
vector<pair<int, int> >e[2];
int id(int a, int b) { return a * 2 * n + b; }
int check(int pos) { return pos >= 0 && pos < 2 * n; }
int dfs(int p, int a, int b)
{
	for (int i = 0, lim = e[p].size(); i < lim; i++)
	{
		int c = a + e[p][i].first, d = b + e[p][i].second;
		if (!check(c) || !check(d))continue;
		if (!col[p][id(c, d)])
		{
			col[p][id(c, d)] = -col[p][id(a, b)];
			dfs(p, c, d);
		}
	}
	return 0;
}
int main()
{
	cin >> n >> d[0] >> d[1];
	for (int p = 0; p <= 1; p++)
		for (int x = 0; x <= d[p]; x++)
		{
			int y = sqrt(d[p] - x * x);
			if (x * x + y * y != d[p])continue;
			e[p].push_back(make_pair(x, y));
			e[p].push_back(make_pair(-x, y));
			e[p].push_back(make_pair(x, -y));
			e[p].push_back(make_pair(-x, -y));
		}
	for (int i = 0; i < 2 * n; i++)
		for (int j = 0; j < 2 * n; j++)
			for (int p = 0; p <= 1; p++)
				if (!col[p][id(i, j)])
				{
					col[p][id(i, j)] = 1;
					dfs(p, i, j);
				}
	int now,haha;
	int tot = 0;
	for (int i = 0; i < 2 * n; i++)
		for (int j = 0; j < 2 * n; j++)
			if (col[0][id(i, j)] == 1 && col[1][id(i, j)] == 1)
			{
				printf("%d %d\n", i, j);
				if (++tot == n * n)return 0;
			}
	return 0;
}