#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
//#include"testlib.h"
#define endl "\n"
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define sz(s)    (int)(s.size())
#define PI acos(-1)
#define EPS 1e-8
#define watch(x) cout << (#x)<<" = "<<x<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("street.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
int mod = 998244353;
ll fpow(ll x, ll p) {
	if (!p)
		return 1;
	ll sq = fpow(x, p / 2);
	sq *= sq;
	sq %= mod;
	if (p & 1)
		sq *= x;
	return sq % mod;
}
const int N = 2e5 + 9;
ll fact[N];
void preProc() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i < N; i++)
		fact[i] = (fact[i - 1] * i) % mod;
}
ll nCrMod(ll n, ll r) {
	// you must call preProc before using nCr
	// you must modify mod first
	// you must modify N
	if (n < r) return 0;
	return (fact[n] * fpow((fact[n - r] * fact[r]) % mod, mod - 2LL)) % mod;
}
int main() {
	file();
	fast();
	preProc();
	ll n, m, k; cin >> n >> m >> k;
	if (k == n - 1)
		RT(fpow(m, n) << endl);
	ll ans = 0;
	for (int i = 0; i <= k; i++) {
		ll num = m * nCrMod(n - 1, i);
		num %= mod;
		num *= fpow(m - 1, n - i - 1);
		num %= mod;
		ans += num;
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}