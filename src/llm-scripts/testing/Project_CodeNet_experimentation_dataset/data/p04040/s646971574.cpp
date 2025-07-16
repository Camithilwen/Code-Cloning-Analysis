#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> inline void read(T &x) {
	x = 0; RG char c = getchar(); bool f = 0;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); if (c == '-') c = getchar(), f = 1;
	while (c >= '0' && c <= '9') x = x*10+c-48, c = getchar();
	x = f ? -x : x;
	return ;
}
template<class T> inline void write(T x) {
	if (!x) {putchar(48);return ;}
	if (x < 0) x = -x, putchar('-');
	int len = -1, z[20]; while (x > 0) z[++len] = x%10, x /= 10;
	for (RG int i = len; i >= 0; i--) putchar(z[i]+48);return ;
}
const int N = 200010, Mod = 1e9 + 7;
int fac[N], ifac[N], H, W, A, B;
int fpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1ll * a * a % Mod)
		if (b & 1) res = 1ll * res * a % Mod;
	return res;
}
int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % Mod * ifac[n - m] % Mod;
}
int calc(int n, int m) {
	return C(n + m - 2, n - 1);
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(H), read(W), read(A), read(B);
	fac[0] = 1;
	for (int i = 1; i <= 200000; i++)
		fac[i] = 1ll * fac[i - 1] * i % Mod;
	ifac[200000] = fpow(fac[200000], Mod - 2);
	for (int i = 200000; i >= 1; i--)
		ifac[i - 1] = 1ll * ifac[i] * i % Mod;
	int ans = 0;
	for (int i = B + 1; i <= W; i++)
		(ans += 1ll * calc(H - A, i) * calc(A, W - i + 1) % Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}
