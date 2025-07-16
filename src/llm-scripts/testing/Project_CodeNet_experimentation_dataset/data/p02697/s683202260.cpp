#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define SZ(a) ((int)a.size())
#define int long long




typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 5e5 + 100;
const int mod = 998244353;
const int Maxn = 1e5;
const int oo = 1e18;
const double PI = ((double)2.00 * (double)asin(1));

struct query {
	int lef, rig, x;
} q[N];
int n, m, k;
int dp[N], g[N], a[N], lst[N];
vector<ii> even, odd, tmp;

int add(int x, int y) { return (x + y + 2 * mod) % mod; }
int mul(int x, int y) { return (x * y) % mod; }

int pw(int x, int y) {
	int res = 1;
	while(y) {
		if(y % 2) res = mul(res, x);
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}

int solve()	{

	memset(dp, 0, sizeof dp);
	for(auto v: odd) {
		a[v.fi] ++, a[v.se + 1] -= 1;
	}

	FOR(i, 1, n) a[i] += a[i - 1];
	FOR(i, 1, n) {
		a[i] = min(a[i], 1ll);
		//cout << a[i] << ' ';
	}  //cout << '\n';

	

	sort(tmp.begin(), tmp.end()); 	
	for(auto v: tmp) {
		while(SZ(even) > 0 && even.back().se >= v.se) even.pop_back();
		even.pb(v);
	}

	if(!SZ(even)) {
		int res = 1;
		FOR(i, 1, n) if(!a[i]) res = mul(res, 2);
		return res;
	}

	//for(auto v: even) cout << v.fi << ' ' << v.se << '\n'; cout << '\n';
	int pos = 0, pos1 = 0;
	FOR(i, 1, n) {
		while(pos < SZ(even) && even[pos].se < i) pos += 1;
		if(pos > 0) lst[i] = even[pos - 1].fi;
		else lst[i] = 0;
	}
	dp[0] = g[0] = 1;
	FOR(i, 1, n) {
		if(a[i]) {
			g[i] = g[i - 1];
			dp[i] = 0;
		} else {
			// set a[i] = 0
			if(lst[i] == 0) dp[i] = g[i - 1];
			else dp[i] = add(g[i - 1], -g[lst[i] - 1]);
			g[i] = add(dp[i], g[i - 1]);
		}
		//cout << dp[i] << ' ';
	} //cout << '\n';
	
	int res = 0;

	FOR(i, 1, n) if(even.back().fi <= i)
		res = add(res, dp[i]);

	return res;
}

signed main() {
	#ifdef TEST
	freopen("test.inp", "r", stdin);
	//freopen("athletic.in", "r", stdin);
	//freopen("athletic.out", "w", stdout);
	#endif //TEST

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	int even = m / 2, odd = (m + 1) / 2;
	FOR(i, 1, odd) cout << i << ' ' << 2 * odd - i + 1 << '\n';
	FOR(i, 1, even) cout << 2 * odd + i << ' ' << 2 * odd + 2 * even + 1 - i + 1 << '\n';
}
