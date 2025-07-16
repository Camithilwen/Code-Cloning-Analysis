#include "bits/stdc++.h"
using namespace std;
#ifndef LOCAL
#define endl '\n'
#endif

#define fr(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, a, b) for(int i = a; i >= b; i--)
#define pf push_front
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound

typedef long long ll;
typedef long double f80;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int pct(int x) { return __builtin_popcount(x); }
int pct(ll x) { return __builtin_popcountll(x); }
int bt(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))
int bt(ll x) { return 63 - __builtin_clzll(x); } // floor(log2(x))
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
ll cdiv(ll a, ll b) { return a / b + !(a < 0 || a % b == 0); }
int nxt_C(int x) { int c = x & -x, r = x + c; return (((r ^ x) >> 2) / c) | r; }
ll nxt_C(ll x) { ll c = x & -x, r = x + c; return (((r ^ x) >> 2) / c) | r; }

vector<int> get_bits(int mask) {
	vector<int> bb;
	while(mask) { int b = bt(mask); bb.pb(b); mask ^= (1 << b); }
	reverse(all(bb));
	return bb;
}

int get_mask(vector<int> v) {
	int mask = 0;
	for(int x : v) { mask ^= (1 << x); }
	return mask;
}

template<typename T>
void uniq(vector<T> &v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

void sc() {}

template <typename Head, typename... Tail>
void sc(Head &H, Tail &... T) { cin >> H; sc(T...); }

#ifdef LOCAL
#define debug(...) cerr << "[L:" << __LINE__ << "][" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// #ifndef LOCAL
// string to_string(__int128 x) {
// 	string s = "";
// 	bool neg = 0;
// 	if(x < 0) { s += "-"; neg = 1; x = -x; }
// 	if(!x) s += '0';
// 	while(x) {
// 		int rem = x % 10;
// 		s += to_string(rem);
// 		x /= 10;
// 	}
// 	reverse(s.begin() + neg, s.end());
// 	return s;
// }
// #endif

const int mod = 1e9 + 7; // 998244353;

int pwr(int a,ll b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

/*
	Lookout for overflows!!
	Check array sizes!!
	Clear before test cases!!
	Use the correct modulo!!
	Check for corner cases!!
	Are you forgetting something?!
	Read problem statement carefully!!!
*/

const int N = 2e5 + 5;
int a[N];

void solve() {
	int n;
    sc(n);
    fr(i, 0, n - 1) {
        sc(a[i]);
        a[i] = i - a[i];
        debug(a[i]);
    }
    if(a[0] != 0) {
        cout << -1;
        return;
    }
    fr(i, 0, n - 2) {
        if(a[i] > a[i + 1]) {
            cout << -1;
            return;
        }
    }
    ll ans = n - 1 - a[n - 1];
    rf(i, n - 1, 1) {
        if(a[i] != a[i - 1]) { ans += i - 1 - a[i - 1]; debug(i - 1, ans); }
    }
    cout << ans;
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		solve();
	}
	return 0;
}