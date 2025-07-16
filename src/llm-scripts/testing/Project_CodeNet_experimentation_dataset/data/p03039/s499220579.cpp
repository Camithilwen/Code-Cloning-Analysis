#include <cstdio>
#define ll long long
ll mod = 1000000007;
ll big(ll b, ll p){
	if (p == 1) return b;
	ll h = big(b, p / 2);
	ll res = (h * h) % mod;
	if (p % 2 == 1) res = (res * b) % mod;
	return res;
}
int main(){
	ll n, m, k, ans = 1, x = 0, y = 0;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 2; i < k; i++){
		ans *= (n * m) - i;
		ans %= mod;
	}
	for (int i = 1; i < n; i++){
		x += i * (n - i);
		x %= mod;
	}
	x = (x * m) % mod;
	x = (x * m) % mod;
	for (int i = 1; i < m; i++){
		y += i * (m - i);
		y %= mod;
	}
	y = (y * n) % mod;
	y = (y * n) % mod;
	ans = ans * (x + y) % mod;
	for (int i = k - 2; i > 1; i--){
		ans = (ans * big(i, mod - 2)) % mod;
	}
	printf("%lld\n", ans);
}