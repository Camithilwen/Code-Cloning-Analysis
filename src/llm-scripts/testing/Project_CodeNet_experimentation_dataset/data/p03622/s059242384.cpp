#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define mod 998244353
#define MAXN 1000005

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int n,m,fac[MAXN],ifac[MAXN];

int mul (int a,int b){return 1ll * a * b % mod;}
int dec (int a,int b){return a >= b ? a - b : a + mod - b;}
int add (int a,int b){return a + b >= mod ? a + b - mod : a + b;}
int qkpow (int a,int b){int res = 1;for (;b;b >>= 1,a = mul (a,a)) if (b & 1) res = mul (res,a);return res;}
int binom (int a,int b){return mul (fac[a],mul (ifac[b],ifac[a - b]));}
int inv (int x){return qkpow (x,mod - 2);}

signed main(){
	read (n,m);
	fac[0] = 1;for (Int i = 1;i <= n + m;++ i) fac[i] = mul (fac[i - 1],i);
	ifac[n + m] = inv (fac[n + m]);for (Int i = n + m;i;-- i) ifac[i - 1] = mul (ifac[i],i);
	int res = 0;for (Int i = 1;i <= n && i <= m;++ i) res = add (res,mul (binom (2 * i,i),binom (n + m - 2 * i,n - i)));
	res = mul (res,mul (ifac[2],inv (binom (n + m,n))));
	write (add (res,max (n,m))),putchar ('\n');
	return 0;
}