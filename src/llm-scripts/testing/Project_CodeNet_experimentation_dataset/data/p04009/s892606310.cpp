#include <algorithm>
#include <cstdio>
char str[105];
int row_pre[105][105], col_pre[105][105], dp[105][105][105][105];
int main()
{
	// freopen("AGC004-E.in", "r", stdin);
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < m; j++)
		{
			row_pre[i][j] = (j ? row_pre[i][j - 1] : 0) + (str[j] == 'o');
			col_pre[i][j] = (i ? col_pre[i - 1][j] : 0) + (str[j] == 'o');
			if (str[j] == 'E')
			{
				x = i;
				y = j;
			}
		}
	}
	auto calc_row = [&] (int idx, int l, int r)
	{
		int ll = std::max(l, r - y), rr = std::min(r, m - 1 - y + l);
		if (ll > rr)
			return 0;
		return row_pre[idx][rr] - (ll ? row_pre[idx][ll - 1] : 0);
	};
	auto calc_col = [&] (int idx, int l, int r)
	{
		int ll = std::max(l, r - x), rr = std::min(r, n - 1 - x + l);
		if (ll > rr)
			return 0;
		return col_pre[rr][idx] - (ll ? col_pre[ll - 1][idx] : 0);
	};
	auto upd = [&] (int &a, const int &b)
	{
		if (a < b)
			a = b;
	};
	for (int i = 0; i <= x; i++)
	{
		for (int j = n - 1; j >= x; j--)
		{
			for (int k = 0; k <= y; k++)
			{
				for (int t = m - 1; t >= y; t--)
				{
					if (i > j - x)
						upd(dp[i][j][k][t], dp[i - 1][j][k][t] + calc_row(i - 1, k, t));
					if (j < n - 1 - x + i)
						upd(dp[i][j][k][t], dp[i][j + 1][k][t] + calc_row(j + 1, k, t));
					if (k > t - y)
						upd(dp[i][j][k][t], dp[i][j][k - 1][t] + calc_col(k - 1, i, j));
					if (t < m - 1 - y + k)
						upd(dp[i][j][k][t], dp[i][j][k][t + 1] + calc_col(t + 1, i, j));
				}
			}
		}
	}
	printf("%d\n", dp[x][x][y][y]);
	return 0;
}
