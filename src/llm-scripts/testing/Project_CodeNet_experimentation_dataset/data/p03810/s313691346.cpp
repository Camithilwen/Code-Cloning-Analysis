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
int n, a[maxn];
inline bool get() {
	int s = 0, one = 0;
	rep(i, 1, n) s += a[i] % 2, one = one || a[i] == 1;
	if(s != 1 || one) return n - s & 1;
	int gcd = 0;
	for(int i = 1;i <= n;++i) gcd = std::__gcd(gcd, a[i] -= a[i] % 2);
	for(int i = 1;i <= n;++i) a[i] /= gcd;
	return get() ^ 1;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cout << (get() ? "First" : "Second") << '\n';
}
