/// In The Name Of God

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)2000 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)998244353;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int sum(int x, int y) {
	add(x, y);
	return x;
}
int mult(int x, int y) {
	return x * 1ll * y % mod;
}

int bp(int x, int y) {
	if (x < 0) return 0;
	int res = 1;
	while (y) { 
		if (y & 1) res = res * 1ll * x;
		x = x * 1ll * x % mod, y >>= 1;
	}
	return res;
}

int n, k;

int dp[N][N][2];
int calc(int ost, int prs, int f) {
	if (ost < 0) return 0;
	if (!ost) return 1;
	if (~dp[ost][prs][f]) return dp[ost][prs][f];
	int res = 0;
	if (prs) add(res, calc(ost, prs - 1, 1));
	if (f) {
		if (prs) add(res, calc(ost - 1, prs, 0) * 2ll % mod);
	} else {
		add(res, calc(ost - 1, prs, 0));
	}
	return dp[ost][prs][f] = res;
}
int dp1[N][N];
int calc1(int ost, int cnt) {
	if (ost < 0) return 0;
	if (!ost || cnt <= 0) return !ost;
	if (~dp1[ost][cnt]) return dp1[ost][cnt];
	int res = calc1(ost, cnt - 1);
	if (cnt) add(res, calc1(ost - 1, cnt));
	return dp1[ost][cnt] = res;
}
int total(int K) {
	int prs = 0;
	rep(i, 1, K) {
		prs += (K - i <= k && i < K - i);
	}	
	int res = 0;
	rep(i, 0, n) {
		int cnt1 = sum(calc(i, prs, 1), calc(i - 1, prs, 1) * (K % 2 == 0 && K / 2 <= k));
		/* cout << calc(i, prs, (K % 2 == 0 && K / 2 <= n), 1) << nl;
		cout << calc1(n - i, k - 2 * prs - (K % 2 == 0 && K / 2 <= n)) << nl;
		cout << nl; */
		add(res, mult(cnt1, calc1(n - i, k - 2 * prs - (K % 2 == 0 && K / 2 <= k))));
	}
	return res;
}
int main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	cin >> k >> n;
	memset(dp, -1, sizeof(dp));
	memset(dp1, -1, sizeof(dp1));
	rep(i, 2, 2 * k) {
		cout << total(i) << nl;
	}
	ioi
}

