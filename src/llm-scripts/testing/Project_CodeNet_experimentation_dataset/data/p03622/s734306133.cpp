#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 998244353
#define ll long long
#define N 1000005
#define inv 499122177

using namespace std;

int n, m;
ll fac[N], ifac[N];
ll ans;

void init();
ll quick_pow(ll ,int);
ll C(int ,int);

int main(){
	cin >> n >> m;init();
	if(n < m) swap(n, m);
	for(int i = 1; i <= m; ++i){
		int x = n - i, y = m - i;
		(ans += C(i, 2 * i) * C(x, x + y) % mod) %= mod;
	}
	(ans *= quick_pow(C(n, n + m), mod - 2) * inv % mod) %= mod;
	(ans += n) %= mod;
	cout << ans << endl;
}

void init(){
	fac[0] = 1;ifac[0] = 1;
	for(int i = 1; i <= 1e6; ++i)
		fac[i] = fac[i - 1] * i % mod, ifac[i] = quick_pow(fac[i], mod - 2);
	return ;
}

ll C(int x,int y){
	return fac[y] * ifac[y - x] % mod * ifac[x] % mod;
}

ll quick_pow(ll x,int y){
	ll sum = 1, a = x;
	while(y){
		if(y & 1) (sum *= a) %= mod;
		(a *= a) %= mod;
		y >>= 1;
	}
	return sum;
}
