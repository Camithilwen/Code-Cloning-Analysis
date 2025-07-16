#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

ll nax = 1005;
VLL p(nax*nax, 1);
VLL P;

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}

		P.push_back(x);
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}
}

map<ll,ll> pf(ll x) {
    map<ll,ll> f;
    REP(i,0,sz(P)) {
        if (P[i] * P[i] > x) break;
        while (x % P[i] == 0) {
            f[P[i]]++;
            x /= P[i];
        }
    }
    if (x > 1) f[x]++;
    return f;
}

VLL F(100500, -1);
VLL INVF(100500, -1);

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

ll f(ll x) {
	if (F[x] != -1) return F[x];
	if (x == 0) return 1;
	F[x] = f(x-1) * x % mod;
	return F[x];
}

ll invf(ll x) {
	if (INVF[x] != -1) return INVF[x];
	INVF[x] = pow(f(x), mod-2);
	return INVF[x];
}

ll ncr(ll n, ll r) {
	// n! / r! / (n-r)!
	ll ans = f(n);
	ans *= invf(r);
	ans %= mod;
	ans *= invf(n-r);
	ans %= mod;
	return ans;
}


void solve() {
	ll n, m;
	in(n, m);

	map<ll,ll> factors = pf(m);

	REP(i,0,n) f(i); // ease on the recursion

	ll ans = 1;
	for (PLL a : factors) {
		ans *= ncr(a.second + n - 1, a.second) % mod;
		ans %= mod;
	}
	cout << ans << endl;


}

signed main() {
	init();
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}