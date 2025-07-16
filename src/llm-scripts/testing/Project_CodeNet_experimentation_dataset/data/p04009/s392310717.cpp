#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100 + 5;

int n, m;
char gra[MAXN][MAXN];
short sum[MAXN][MAXN];
int ex, ey;
short f[MAXN][MAXN][MAXN][MAXN];

int get_sum(int x1, int y1, int x2, int y2)
{
	if(x1 > x2 || y1 > y2)
		return 0;
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int dp(int x1, int y1, int x2, int y2)
{
	if(x1 > x2 || y1 > y2)
		return 0;
	if(f[x1][y1][x2][y2] != -1)
		return f[x1][y1][x2][y2];
	int ret = 0, tot = get_sum(x1, y1, x2, y2);
	// cut left
	if(ret < tot)
		ret = max(ret, dp(x1, y1 + 1, x2, y2) + 
			(y1 + m - y2 < ey ? 0 : get_sum(max(x1, ex - n + x2), y1, min(x2, ex + x1 - 1), y1)));
	// cut right
	if(ret < tot)
		ret = max(ret, dp(x1, y1, x2, y2 - 1) +
			(y2 + 1 - y1 > ey ? 0 : get_sum(max(x1, ex - n + x2), y2, min(x2, ex + x1 - 1), y2)));
	// cut up
	if(ret < tot)
		ret = max(ret, dp(x1 + 1, y1, x2, y2) + 
			(x1 + n - x2 < ex ? 0 : get_sum(x1, max(y1, ey - m + y2), x1, min(y2, ey + y1 - 1))));
	// cut up
	if(ret < tot)
		ret = max(ret, dp(x1, y1, x2 - 1, y2) + 
			(x2 + 1 - x1 > ex ? 0 : get_sum(x2, max(y1, ey - m + y2), x2, min(y2, ey + y1 - 1))));
	// cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << ret << endl;
	return f[x1][y1][x2][y2] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> (gra[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (gra[i][j] == 'o');
			if(gra[i][j] == 'E')
				ex = i, ey = j;
		}
	// cout << sum[n][m] << endl;

	memset(f, -1, sizeof(f));

	int ans = dp(1, 1, n, m);

	cout << ans << endl;

	return 0;
}
