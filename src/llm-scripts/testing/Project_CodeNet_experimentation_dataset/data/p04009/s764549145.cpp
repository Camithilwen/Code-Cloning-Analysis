#include <algorithm>
#include <cstdio>
#define upd(x, y) (x) = std::max(x, y)
char str[105];
int dp[105][105][105][105], row_pre[105][105], col_pre[105][105];
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
			col_pre[j][i] = (i ? col_pre[j][i - 1] : 0) + (str[j] == 'o');
			if (str[j] == 'E')
			{
				x = i;
				y = j;
			}
		}
	}
	auto calc_row = [&] (int row, int l, int r)
	{
		int L = std::max(l, r - y), R = std::min(r, l + m - y - 1);
		return L <= R ? row_pre[row][R] - (L ? row_pre[row][L - 1] : 0) : 0;
	};
	auto calc_col = [&] (int col, int l, int r)
	{
		int L = std::max(l, r - x), R = std::min(r, l + n - x - 1);
		return L <= R ? col_pre[col][R] - (L ? col_pre[col][L - 1] : 0) : 0;
	};
	for (int i = 0; i <= x; i++)
	{
		for (int j = n - 1; j >= x; j--)
		{
			for (int k = 0; k <= y; k++)
			{
				for (int t = m - 1; t >= y; t--)
				{
					if (j - i < x)
						upd(dp[i][j][k][t], dp[i - 1][j][k][t] + calc_row(i - 1, k, t));
					if (j - i < n - x - 1)
						upd(dp[i][j][k][t], dp[i][j + 1][k][t] + calc_row(j + 1, k, t));
					if (t - k < y)
						upd(dp[i][j][k][t], dp[i][j][k - 1][t] + calc_col(k - 1, i, j));
					if (t - k < m - y - 1)
						upd(dp[i][j][k][t], dp[i][j][k][t + 1] + calc_col(t + 1, i, j));
				}
			}
		}
	}
	printf("%d\n", dp[x][x][y][y]);
	return 0;
}
