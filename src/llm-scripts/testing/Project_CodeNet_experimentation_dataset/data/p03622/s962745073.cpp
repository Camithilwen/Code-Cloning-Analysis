#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
#define P	998244353
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
long long fac[MAXN], inv[MAXN];
void update(long long &x, long long y) {
	x = (x + y) % P;
}
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
long long getc(long long x, long long y) {
	return fac[x] * inv[y] % P * inv[x - y] % P;
}
int main() {
	int n, m;
	read(n), read(m);
	if (n < m) swap(n, m);
	fac[0] = 1;
	for (int i = 1; i <= n + m; i++)
		fac[i] = fac[i - 1] * i % P;
	inv[n + m] = power(fac[n + m], P - 2);
	for (int i = n + m - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % P;
	long long ans = 0;
	for (int i = 1; i <= m; i++)
		update(ans, getc(2 * i, i) * getc(n + m - 2 * i, m - i));
	ans = ans * power(getc(n + m, m) * 2 % P, P - 2) % P;
	update(ans, n);
	cout << ans << endl;
	return 0;
}