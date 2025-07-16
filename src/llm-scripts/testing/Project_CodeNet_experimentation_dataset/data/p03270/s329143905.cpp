#include <cstdio>
#include <iostream>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#define inver(a) power(a, mod - 2)

using namespace std;

inline char nc()
{
	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x)
{
	x=0; int f=1,ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x*=f;
}

typedef long long ll;

const int mod = 998244353;
const int MAXK = 2000 + 5;
const int MAXN = 2000 + 5;
int K, N;

inline int add(int x) {return x >= mod ? x - mod : x;}
ll power(ll x, ll y)
{
	ll re = 1;
	while(y)
	{
		if(y & 1) re = re * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return re;
}

const int maxn = MAXN + MAXK;
int fac[maxn];
int inv[maxn];
void init_binom(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		fac[i] = (ll)fac[i - 1] * i % mod;
	}
	inv[n] = inver(fac[n]);
	for(int i = n; i >= 1; --i)
	{
		inv[i - 1] = (ll)inv[i] * i % mod;
	}
}
int binom(int x, int y)
{
	if(x < y) return 0;
	return (ll)fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int F(int x, int y)
{
	if(x == 0 && y == 0) return 1;
	return binom(x + y - 1, x);
}

int sol(int k, int n, int m)
{
	int an = 0;
	for(int j = 0, p = 1; j <= m && j <= n; ++j)
	{
		an = (an + (ll)binom(m, j) * F(n - j, k - 2 * m + j) % mod * p) % mod;
		p = add(p << 1);
	}
	return an;
}

int main()
{
	read(K), read(N);
	init_binom(K + N);
	for(int i = 2; i <= 2 * K; ++i)
	{
		int m = 0;
		for(int a = 1, b = i - 1; a < b; ++a, --b)
		{
			if(b <= K) ++m;
		}
		if(i & 1) printf("%d\n", sol(K, N, m));
		else printf("%d\n", add(sol(K - 1, N, m) + sol(K - 1, N - 1, m)));
	}
	return 0;
} 