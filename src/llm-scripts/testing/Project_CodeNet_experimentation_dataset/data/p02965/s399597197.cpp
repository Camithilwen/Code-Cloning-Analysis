#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define inver(a) power(a, mod - 2)
#define F(x, y) C(x - 1 + y, y)
using namespace std;
inline char nc()
{
    return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x)
{
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
typedef long long ll;
const int mod = 998244353;
const int maxn = 2000050;
int n, m;
int fac[maxn];
int fac_inv[maxn];
inline int dec(int x) {return x < 0 ? x + mod : x;}
inline ll C(int x, int y)
{
    return (ll)fac[x] * fac_inv[y] % mod * fac_inv[x - y] % mod;
}
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
void init(int n)
{
    fac[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        fac[i] = (ll)fac[i - 1] * i % mod;
    }
    fac_inv[n] = inver(fac[n]);
    for(int i = n; i >= 1; --i)
    {
        fac_inv[i - 1] = (ll)fac_inv[i] * i % mod;
    }
}
int cal(int x, int y)
{
    int re = F(n, x);
    re = dec(re - y * F(n, x - m) % mod);
    if(x > m) re = dec(re - (n - y) * F(n, x - m - 1) % mod);
    return re;
}
int solve()
{
    int an = 0;
    for(int i = 0; i <= min(m, n); ++i)
    {
        if((3 * m - i) & 1) continue;
        an = (an + cal((3 * m - i) >> 1, i) * C(n, i)) % mod;
    }
    return an;
}
int main()
{
    read(n), read(m);
    init(n + (m << 1));
    printf("%d\n", solve());
    return 0;
}
