#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int MAXN = 1e4 + 10;
ll dp[MAXN][128], num[MAXN];
char s[MAXN];
int len, D;

ll dfs(int pos, int tot, bool lim) {
	if (pos == len + 1) return dp[pos][tot] = (tot == 0);
	if (!lim && dp[pos][tot] != -1) return dp[pos][tot];
	int up = lim ? num[pos] : 9;
	ll ret = 0;
	for (int i = 0; i <= up; i++) {
		ret += dfs(pos + 1, (tot + i) % D, lim && (i == up));
		ret %= mod;
	}
	if (!lim) dp[pos][tot] = ret;
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s%d", s + 1, &D);
	len = strlen(s + 1);
	for (int i = 1; i <= len; i++) num[i] = s[i] - '0';
	ll ans = (dfs(1, 0, 1) - 1 + mod) % mod;
// minus one to deduct the zero
	cout << ans << endl;
	return 0;
}
 