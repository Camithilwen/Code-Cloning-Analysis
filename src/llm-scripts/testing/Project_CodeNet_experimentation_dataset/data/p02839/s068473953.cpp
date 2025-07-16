#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

bool dp[82][82][128002];

void solve_abc_e() {
	ll h, w;
	ll ans = 0;

	cin >> h >> w;

	ll a[82][82], b[82][82], c[82][82];

	rep(i, 82)rep(j, 82) {
		a[i][j] = b[i][j] = c[i][j] = 0;
	}

	rep(i, h)rep(j, w) {
		cin >> a[i][j];
	}
	rep(i, h)rep(j, w) {
		cin >> b[i][j];
	}

	rep(i, h)rep(j, w) {
		c[i][j] = abs(a[i][j] - b[i][j]);

	}


	dp[0][0][c[0][0]] = true;
	rep(i, h)rep(j, w) {
		rep(p, 128001) {
			if (dp[i][j][p]) {
				dp[i + 1][j][abs(p + c[i + 1][j])] = true;
				dp[i + 1][j][abs(p - c[i + 1][j])] = true;
				dp[i][j + 1][abs(p + c[i][j + 1])] = true;
				dp[i][j + 1][abs(p - c[i][j + 1])] = true;
			}
		}
	}

	rep(p, 128001) {
		if (dp[h - 1][w - 1][p]) {
			cout << p << "\n";
			return;
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_e();

	return 0;
}