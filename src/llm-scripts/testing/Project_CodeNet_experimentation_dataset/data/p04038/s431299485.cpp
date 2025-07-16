#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
struct perm {
private:
	int sz;
	vector<ll> p, invp;
public:
	perm(int n) {
		sz = n + 1;
		p.resize(sz), invp.resize(sz);
		p[0] = 1;
		rep1(i, sz - 1) {
			p[i] = p[i - 1] * i%mod;
		}
		invp[sz - 1] = 1;
		ll cop = mod - 2, x = p[sz - 1];
		while (cop) {
			if (cop % 2)invp[sz - 1] = invp[sz - 1] * x%mod;
			cop >>= 1; x = x * x % mod;
		}
		per(i, sz - 1) {
			invp[i] = invp[i + 1] * (i + 1) % mod;
		}
	}
	ll comb(ll x, ll y) {
		if (x < y || y < 0)return 0;
		ll ret = p[x];
		(ret *= invp[y]) %= mod;
		(ret *= invp[x - y]) %= mod;
		return ret;
	}
	ll combP(ll x, ll y) {
		if (x < y || y < 0)return 0;
		return p[x] * invp[x - y] % mod;
	}
};
perm pm(1 << 22);

ll dp[2001];
ll rdp[2002];
ll nex[2001];

void solve() {
	int n, k; cin >> n >> k;
	if (k == 1) {
		cout << 1 << endl; return;
	}
	dp[1] = 1;
	for (int i = 2; i < 2002; i++)rdp[i] = 1;
	rep1(i, n - 1) {
		for (int j = 1; j <= i + 1; j++) {
			int num = i * k - (j - 1);
			nex[j] = (rdp[i + 1] - rdp[j - 1])*pm.comb(num + k - 2, num);
			nex[j] = (nex[j] % mod + mod) % mod;
		}
		for (int j = 1; j <= i + 1; j++) {
			dp[j] = nex[j];
			rdp[j + 1] = (rdp[j] + dp[j]) % mod;
		}
	}
	ll ans = rdp[n + 1];
	rep1(i, n)ans = ans * i%mod;
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//stop
	return 0;
}
