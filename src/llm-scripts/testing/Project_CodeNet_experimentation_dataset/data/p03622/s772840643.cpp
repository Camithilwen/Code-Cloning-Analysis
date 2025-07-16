#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define ri rd<int>
using namespace std;
const int mod = 998244353;
const int maxN = 1e6 + 7;

inline int pls(int x, int y) {return (x + y) % mod;}
inline int mns(int x, int y) {return pls(x, mod - y);}
inline int mul(int x, int y) {return 1LL * x * y % mod;}
inline void Add(int &x, int y) {x = pls(x, y);}
inline void Mul(int &x, int y) {x = mul(x, y);}

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

int n, m;
int iv[maxN];
int fac[maxN], ifac[maxN];

inline int C(int x, int y) {return (y <= x) ? mul(mul(fac[x], ifac[y]), ifac[x - y]) : 0;}
inline int ways(int x, int y) {return C(x + y, y);}

int main() {

	n = ri(), m = ri();
	if (n < m) swap(n, m);
	iv[1] = 1; rep (i, 2, n + m) iv[i] = mul(iv[mod % i], mod - mod / i);
	fac[0] = 1; rep (i, 1, n + m) fac[i] = mul(fac[i - 1], i);
	ifac[0] = 1; rep (i, 1, n + m) ifac[i] = mul(ifac[i - 1], iv[i]);
	
	int res = 0;
	Add(res, mul(ways(n, m), n));
	rep (i, 1, m) Add(res, mul(iv[2], mul(ways(i, i), ways(n-i, m-i))));

	printf("%d\n", mul(res, mul(mul(ifac[n+m], fac[m]), fac[n])));

	return 0;
}