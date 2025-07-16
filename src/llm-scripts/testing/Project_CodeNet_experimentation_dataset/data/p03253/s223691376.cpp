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

const ll nax = 100500;
ll F[nax], INVF[nax];

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

ll ncr(ll n, ll r) {
	// n! / r! / (n-r)!
	ll ans = F[n];
	ans *= INVF[r];
	ans %= mod;
	ans *= INVF[n-r];
	ans %= mod;
	return ans;
}


void solve() {
	ll n, m;
	in(n, m);

	F[0] = 1;
	REP(i,1,nax) F[i] = (F[i-1] * i) % mod;
	REP(i,0,nax) INVF[i] = pow(F[i], mod-2);

	map<ll,ll> factors;
	ll f = 2;
	while (m != 1 && f*f <= m) {
		while (m % f == 0) {
			factors[f]++;
			m /= f;
		}
		f++;
	}
	if (m != 1) factors[m]++;

	ll ans = 1;
	for (PLL a : factors) {
		ans *= ncr(a.second + n - 1, a.second) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}