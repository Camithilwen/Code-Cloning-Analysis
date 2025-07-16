#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 18;

int n;
char s[100];
LL ans;
LL dp[100][100];

LL solve(vector<int> a, vector <int> b) {
	rep(i, 0, n) rep(j, 0, ss(a)) dp[i][j] = 0;
	dp[0][0] = 1;
	rep(i, 0, n - 1) 
		rep(j, 0, min(i, ss(a))) {
			if (!dp[i][j]) continue;
			int k = i - j;
			if (j < ss(a) && s[a[j]] == s[n + n - i - 1]) dp[i + 1][j + 1] += dp[i][j];
			if (k < ss(b) && s[b[k]] == s[n + n - i - 1]) dp[i + 1][j] += dp[i][j];
		}
	return dp[n][ss(a)];
}

int main() {
	scanf ("%d", &n);
	scanf ("%s", s);
	rep(mask, 0, (1 << n) - 1) {
		vector <int> a, b;
		rep(k, 0, n - 1)
			if (((mask >> k) & 1)) a.pb(k);
			else b.pb(k);
		ans += solve(a, b);
		//if (solve(a, b)) printf ("%d\n", mask);
	}
	printf ("%lld\n", ans);
	
    return 0;
}
