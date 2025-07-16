#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e5 + 5;

const ll INF = 5e16;

int n;
int a[MAXN];

ll brute(int i, int qtt) {
	if (i > n) {
		if (qtt == n/2) return 0;
		else return -INF;
	}

	return max(a[i] + brute(i+2, qtt+1), brute(i+1, qtt));
}

ll memo[MAXN][5];
ll solve(int i, int duplo) {
	if (i > n) return duplo * -INF;

	ll& ret = memo[i][duplo];
	if (ret != -INF) return ret;

	ret = max(ret, a[i] + solve(i+2, duplo));
	if (duplo) ret = max(ret, solve(i+1, duplo-1));

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	if (n <= 10) printf("%lld\n", brute(1, 0));
	else {
		for (int i = 1; i <= n; i++) for (int j = 0; j <= 4; j++)
			memo[i][j] = -INF;

		ll ans = -INF;
		if (n%2 == 0) {
			ans = solve(1, 1);
			ans = max(ans, solve(2, 0));
		} else {
			ans = solve(1, 2);
			ans = max(ans, solve(2, 1));
		}

		printf("%lld\n", ans);
	}
	
}