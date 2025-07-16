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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = INF/16;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	ll f(ll a, ll b) {
		return min(a, b);
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return INF;
		if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int k, ll x) {
		ll z = query(k, k + 1);
		add(x - z, k, k + 1);
		//cout << query(k, k + 1) << endl;
		//cout << "hello" << k << " " << z << endl;
	}
	ll specialquery(int m) {
		ll res = INF;
		rep(i, m) {
			res = min(res, query(i,i+1) + i);
		}
		return res;
	}
};
int n, q;
ll dp[1 << 18];
int main() {
	cin >> n >> q;
	int a, b; cin >> a >> b; a--; b--;
	fill(dp, dp + n, INF);
	int x; cin >> x; x--;
	dp[a] = abs(b - x); dp[b] = abs(a - x);
	SegT l(n), r(n);
	l.update(a, dp[a]-a); r.update(a, dp[a]+a);
	l.update(b, dp[b]-b); r.update(b, dp[b]+b);
	int memo = x;
	//cout << l.specialquery(n) << endl;
	//cout << r.query(memo, n) - memo << endl;
	rep(i, q - 1) {
		cin >> x; x--;
		ll vl = l.query(0, x) + x;
		ll vr = r.query(x, n) - x;
		//cout << memo << " " << vl << " " << vr << endl;
		dp[memo] = min(vl, vr);
		//cout << memo << " " << dp[memo] << endl;

		l.add(abs(memo - x),0,memo); r.add(abs(memo - x), 0, memo);
		l.add(abs(memo - x), memo + 1, n); r.add(abs(memo - x), memo + 1, n);
		r.update(memo, dp[memo] + memo);
		//cout << memo << " " << dp[memo] - memo << endl;
		l.update(memo, dp[memo] - memo);
		memo = x;
		//cout << l.specialquery() << endl;
	}
	/*cout << l.query(4, 5) + 4 << endl;
	l.update(4, 3);
	cout << l.query(4, 5) + 4 << endl;
    l.specialquery(n);*/
	cout << l.specialquery(n) << endl;
	//cout << memo << endl;
	//stop
		return 0;
}
