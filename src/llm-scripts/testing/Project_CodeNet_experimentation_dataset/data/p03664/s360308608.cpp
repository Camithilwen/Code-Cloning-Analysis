#include<bits/stdc++.h>
using namespace std;
#define MAXN	16
#define MAXM	32768
#define MAXS	14348907
#define INF	1e9
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int mp[MAXN][MAXN], bit[MAXN];
int ups[MAXM], upt[MAXM];
int sum[MAXN][MAXM], cost[MAXS];
int dp[MAXN][MAXM];
int n, m, goal;
void init() {
	goal = (1 << n) - 1;
	bit[1] = 1;
	for (int i = 2; i <= n; i++)
		bit[i] = bit[i - 1] << 1;
	for (int i = 1; i <= n; i++)
	for (int s = 0; s <= goal; s++) {
		if (s & bit[i]) continue;
		for (int j = 1; j <= n; j++)
			if (s & bit[j]) sum[i][s] += mp[i][j];
	}
	for (int s = 0; s <= goal; s++) {
		int tmp = s, sv = 0, tv = 0, now = 1;
		while (tmp) {
			if (tmp & 1) sv += 2 * now;
			if (tmp & 1) tv += now;
			now *= 3; tmp >>= 1;
		}
		ups[s] = sv; upt[s] = tv;
	}
	for (int s = 0; s <= goal; s++)
	for (int tmp = goal ^ s, t = goal ^ s; t; t = (t - 1) & tmp)
	for (int i = 1; i <= n; i++)
		if (s & bit[i]) cost[ups[s] + upt[t]] += sum[i][t];
}
void update(int &x, int y) {
	x = min(x, y);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		mp[x][y] = mp[y][x] = z;
	}
	init();
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= goal; j++)
		dp[i][j] = INF;
	dp[1][bit[1]] = 0;
	for (int s = 0; s <= goal; s++)
	for (int i = 1; i <= n; i++) {
		if ((bit[i] & s) == 0 || dp[i][s] == INF) continue;
		int ts = s ^ bit[i];
		for (int j = 1; j <= n; j++) {
			if ((bit[j] & s) || mp[i][j] == 0) continue;
			update(dp[j][s ^ bit[j]], dp[i][s] + sum[j][ts]);
		}
		for (int tmp = goal ^ s, t = goal ^ s; t; t = (t - 1) & tmp)
			update(dp[i][s ^ t], dp[i][s] + cost[ups[ts] + upt[t]]);
	}
	cout << dp[n][goal] << endl;
	return 0;
}