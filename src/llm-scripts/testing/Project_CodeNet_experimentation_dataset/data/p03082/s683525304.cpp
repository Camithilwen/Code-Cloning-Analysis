#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define sor(a, l, r) sort(a + l, a + r + 1);
#define reve(a, l, r) reverse(a + l, a + r + 1)
using namespace std;
typedef long long LL;
const int N = 205;
const int MAXN = 100005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

namespace ModCalculator {
	const int MOD = 1e9 + 7;
	inline void Inc(int &x, int y) {
		x += y; if (x >= MOD) x -= MOD;
	}
	inline void Dec(int &x, int y) {
		x -= y; if (x < 0) x += MOD;
	}
	inline int Add(int x, int y) {
		Inc(x, y); return x;
	}
	inline int Sub(int x, int y) {
		Dec(x, y); return x;
	}
	inline int Mul(int x, int y) {
		return 1LL * x * y % MOD;
	}
}
using namespace ModCalculator;

int n, X, a[N];
int dp[2][MAXN];

void init() {
	read(n); read(X);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	sor(a, 1, n);
}

void solve() {
	int pre = 0, cur = 1;
	dp[pre][X] = 1;
	int ans = 0;
	for (int i = n; i >= 1; --i) {
		mset(dp[cur], 0);
		for (int j = 0; j <= X; ++j) {
			Inc(dp[cur][j], Mul(dp[pre][j], i - 1));
			Inc(dp[cur][j % a[i]], dp[pre][j]);
		}
		swap(pre, cur);
	}
	for (int i = 1; i <= X; ++i) {
		Inc(ans, Mul(i, dp[pre][i]));
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
