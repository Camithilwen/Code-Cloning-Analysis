#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 mrand(random_device{}());

#define rep(i , l , r) for (int i = (l); i < (r); ++i)

const int N = 2e6 + 5;
const int mod = 998244353;

int n , m;
int fac[N] , ifac[N];

template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void read(T &x) {
   T f = 1; x = 0;
   char c = getchar();
   for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
   for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
   x *= f;
}

inline int quickpow(int a , int n) {
	int res = 1;
	for (; n; n >>= 1 , a = 1LL * a * a % mod)
		if (n & 1) res = 1LL * res * a % mod;
	return res;
}
inline void inc(int &x , int y) {
	x = x + y < mod ? x + y : x + y - mod;
}
inline void dec(int &x , int y) {
	x = x - y >= 0 ? x - y : x - y + mod;
}
inline void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = 1LL * fac[i - 1] * i % mod;
	ifac[n] = quickpow(fac[n] , mod - 2);
	for (int i = n - 1; i >= 0; --i)
		ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod;
	return;
}
inline int binom(int n , int m) {
	if (n < m) return 0;
	else return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
inline int F(int n , int m , int k) {
	int ret = 0;
	for (int i = 0; i <= k; ++i) {
		if ((m - i) & 1) continue;
		int val = 1LL * binom(n , i) * binom((m - i) / 2 + n - 1 , n - 1) % mod;
		inc(ret , val);
	}
	return ret;
}

int main() {
   	
   	init(2e6);
   	read(n) , read(m);
   	int ans = F(n , 3 * m , m);
   	dec(ans , 1LL * n * F(n , m , m) % mod); 
   	inc(ans , 1LL * n * F(n - 1 , m , m) % mod);
   	printf("%d\n" , ans);
    return 0;
}
