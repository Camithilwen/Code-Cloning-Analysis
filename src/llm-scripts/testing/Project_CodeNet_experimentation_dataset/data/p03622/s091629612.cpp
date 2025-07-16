/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int MOD = 998244353;

typedef long long ll;

inline void add( int &a, int b ) { if ((a += b) >= MOD) a -= MOD; }
inline void sub( int &a, int b ) { if ((a -= b) < 0) a += MOD; }
inline int mul( int a, int b ) { return (ll)a * b % MOD; }

int Pow( int x, ll n ) {
	if (n == 1)	return x;
	int y = Pow(x, n / 2);
	return (n & 1) ? mul(mul(y, y), x) : mul(y, y);
}

int Inv( int a ) { return Pow(a, MOD - 2); }
int Div( int a, int b ) { return mul(a, Inv(b)); }

// int C( int n, int k ) {
// 	int res = 1;
// 	forn(i, k) {
// 		res = mul(res, n - i);
// 		res = mul(res, Inv(i + 1));
// 	}
// 	return res;
// }

const int N = 103;
int f[N][N];

int calc( int a, int b ) {
	if (a < 0 || b < 0) return 0;
	if (a > b) swap(a, b);
	if (!a && !b)
		return 0;
	int &res = f[a][b];
	if (!res) {
		res = mul(Div(a,  a + b), calc(a - 1, b));
		add(res, mul(Div(b, a + b), 1 + calc(a, b - 1)));
	}
	return res;
}

double f2[N][N];
double calc2( int a, int b ) {
	if (a < 0 || b < 0) return 0;
	if (a > b) swap(a, b);
	if (!a && !b)
		return 0;
	double &res = f2[a][b];
	if (res == 0) {
		res = 1. * a / (a + b) * calc2(a - 1, b) +
		  1. * b / (a + b) * (1 + calc2(a, b - 1));
	}
	return res;
}

double calc3( int last, int i, int balance, int n ) {
	double add = 0;
	if (balance == 0 && i < 2 * n)
		add += 0.5;
	// if (balance == 0)
	// 	add += (i - last) / 2, last = i;
	if (i == 2 * n)
		return add;
	if (i + balance < 2 * n) {
		double rest = 2 * n - i, good = (rest + balance) / 2.0;
		add += good / rest * calc3(last, i + 1, balance - 1, n);
		add += (rest - good) / rest * calc3(last, i + 1, balance + 1, n);
	} else {
		add += calc3(last, i + 1, balance - 1, n);
	}
	return add;
}

int main() {
	int n, m;
	cin >> n >> m;
	// assert(n == m);
	if (n < m)
		swap(n, m);
	int res = n, tmp = 0;

	vector<int> fact(2 * n + 1);
	fact[0] = 1;
	forn(i, 2 * n)
		fact[i + 1] = mul(fact[i], i + 1);
	auto C = [&]( int n, int k ) {
		return Div(fact[n], mul(fact[n - k], fact[k]));
	};
	int all = C(n + m, n);

	for (int i = 0; i < m; i++) {
		add(tmp, mul(C(n + m - 2 * (m - i), i), C(2 * (m - i), m - i)));
	}
	add(res, Div(tmp, all * 2 % MOD));
	printf("%d\n", res);
	// printf("%d\n", calc(n, n));
	// printf("%.7f\n", calc2(n, n));
	// printf("%.7f\n", calc3(0, 0, 0, n) + n);
}
 