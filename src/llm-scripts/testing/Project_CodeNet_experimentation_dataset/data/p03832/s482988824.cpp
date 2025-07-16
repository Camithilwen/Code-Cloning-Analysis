#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 1e3 + 5;
const int mod = 1e9 + 7; 
using namespace std;

int n, a, b, c, d, fac[N], inv[N], g[N][N], f[N][N], ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int fpow(int x, int y)
{
	int res = 1;
	for( ; y; y >>= 1, x = 1ll * x * x % mod)
		if(y & 1) res = 1ll * res * x % mod;
	return res; 
}

int C(int n, int m)
{
	if(n < 0 || m < 0 || n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), a = read <int> (), b = read <int> (), c = read <int> (), d = read <int> (); 
	for(int i = (fac[0] = 1); i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = fpow(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
	g[0][0] = 1; 
	for(int res = 1, i = a; i <= b; i++, res = 1)
		for(int j = 1; j <= n && i * j <= n; j++)
			g[i * j][j] = 1ll * g[i * (j - 1)][j - 1] * C(i * j, i) % mod * inv[j] % mod * fac[j - 1] % mod; 
	f[a - 1][0] = 1; 
	for(int i = a; i <= b; i++)
		for(int j = 0; j <= n; j++)
		{
			f[i][j] = f[i - 1][j]; 
			for(int k = c; k <= d; k++)
			{
				if(i * k > j) break; 
				f[i][j] = (1ll * f[i - 1][j - i * k] * C(n - (j - i * k), i * k) % mod * g[i * k][k] + f[i][j]) % mod; 
			}
		}
	printf("%d\n", f[b][n]); 
	return 0; 
}
