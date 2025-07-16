#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 45
#define mod 1000000007
using namespace std;

int n, x, y, z, f[N][(1 << 17) + 5], ans; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int main()
{
	n = read <int> (), x = read <int> (), y = read <int> (), z = read <int> ();
	ans = 1; 
	for(int i = 1; i <= n; i++)
		ans = 1ll * ans * 10 % mod; 
	int sz = (1 << (x + y + z)) - 1, ck = (1 << (x + y + z - 1)) | (1 << (y + z - 1)) | (1 << (z - 1));
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= sz; j++)
			if(f[i - 1][j])
			{
				for(int k = 1; k <= 10; k++)
				{
					int tmp = (j << k) | (1 << (k - 1));
					tmp &= sz;
					if((tmp & ck) != ck) f[i][tmp] = (1ll * f[i][tmp] + f[i - 1][j]) % mod; 
				}
			}
	for(int j = 0; j <= sz; j++)
		ans = ((1ll * ans - f[n][j]) % mod + mod) % mod;
	printf("%d\n", ans); 
	return 0; 
}