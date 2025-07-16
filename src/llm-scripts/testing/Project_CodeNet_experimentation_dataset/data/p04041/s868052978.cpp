#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 45;
const int mod = 1e9 + 7; 
using namespace std;

int n, x, y, z, now, lim, f[N][(1 << 17) + 5], ans; 

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

void output(int x)
{
	int a[100], cnt = 0;
	while(x) a[cnt++] = x & 1, x >>= 1;
	if(!cnt) return (void) (puts("0")); 
	for(int i = cnt - 1; i >= 0; i--) printf("%d", a[i]);
	puts(""); 
}

int main()
{
	n = read <int> (), x = read <int> (), y = read <int> (), z = read <int> ();
	now = (1 << (x - 1 + y + z)) | (1 << (y - 1 + z)) | (1 << (z - 1)), lim = (1 << (x + y + z)) - 1; 
	f[0][0] = 1; 
	for(int tmp, i = 0; i < n; i++)
		for(int j = 0; j <= lim; j++)
			if(f[i][j])
			{
				for(int k = 1; k <= 10; k++)
				{
					tmp = ((j << k) | (1 << (k - 1))) & lim; 
					if((tmp & now) != now) f[i + 1][tmp] = (f[i + 1][tmp] + f[i][j]) % mod; 
				}
			}
	for(int j = 0; j <= lim; j++) if((j & now) != now) ans = (ans + f[n][j]) % mod; 
	printf("%d\n", (fpow(10, n) - ans + mod) % mod); 
	return 0; 
}
