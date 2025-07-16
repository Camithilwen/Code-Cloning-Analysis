/*--------------------------------
  Author: The Ace Bee
  Blog: www.cnblogs.com/zsbzsb
  This code is made by The Ace Bee
--------------------------------*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#define rg register
using namespace std;
template < typename T > inline void read(T& s) {
	s = 0; int f = 0; char c = getchar();
	while (!isdigit(c)) f |= (c == '-'), c = getchar();
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	s = f ? -s : s;
}

const int p = 1000000007;
const int _ = 500010;

int n, m, a, b, fac[_], inv[_];
inline void pre() {
	fac[0] = inv[0] = inv[1] = 1;
	for (rg int i = 1; i < _; ++i) fac[i] = 1ll * i * fac[i - 1] % p;
	for (rg int i = 2; i < _; ++i) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
	for (rg int i = 1; i < _; ++i) inv[i] = 1ll * inv[i - 1] * inv[i] % p;
}

inline int C(int n, int m) { return 1ll * fac[n] * inv[n - m] % p * inv[m] % p; }

inline int calc(int i1, int j1, int i2, int j2) { return C(i2 - i1 + j2 - j1, i2 - i1); }

int main() {
	pre();
	read(n), read(m), read(a), read(b);
	
	int res = 0;
	for (rg int i = 1; i <= n - a; ++i)
		res = (res + 1ll * calc(1, 1, i, b) * calc(i, b + 1, n, m) % p) % p;
	printf("%d\n", res);
	return 0;
}
