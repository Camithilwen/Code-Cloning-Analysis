#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, d;
ll pw[maxn], t;
std::unordered_map<ll, ll> map[100];
inline ll dfs(int high,int can,ll rem) {
	if(high <= 0) return !rem * (high == 0 ? 10 : 1);
	if(!can && map[high].count(rem)) return map[high][rem];
	ll & ans = can ? t = 0 : map[high][rem];
	for(int i = can;i < 10;++i) {
		for(int j = 0;j < 10;++j) {
			ll v = rem + (pw[high] - 1) / 9 * (j - i);
			ans += v % 10 ? 0 : dfs(high - 2, 0, v / 10);
		}
	}
	return ans;
}
int main() {
	rep(i, 1, 20) map[i].rehash(1e5 + 7);
	*pw = 1;
	for(int i = 1;i < 19;++i) pw[i] = pw[i - 1] * 10;
	cin >> d;
	if(d % 9) {
		cout << 0 << '\n';
		return 0;
	}
	ll ans = 0;
	for(n = 1;n < 19;++n) {
		ans += dfs(n, 1, -d / 9);
	}
	cout << ans << '\n';
}
