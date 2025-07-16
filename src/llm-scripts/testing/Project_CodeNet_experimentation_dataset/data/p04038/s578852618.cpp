#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 3000;
const int P = 1e9 + 7;

int n, k;
int fac[N * N], inv[N * N], f[N][N];

int power(int a,int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % P;
		a = a * a % P, b >>= 1;
	}
	return res;
}

int C(int n,int m) {
	int A = fac[n];
	int B = inv[n-m] * inv[m] % P;
	return A * B % P;
}

signed main(void)
{
	cin >> n >> k;
	fac[0] = 1;
	for (int i=1;i<=2100 * 2100;++i)
		fac[i] = fac[i-1] * i % P;
	f[0][0] = 1;
	int MAXN = 2000 * 2000;
	inv[MAXN] = power(fac[MAXN], P - 2);
	for (int i=MAXN - 1;i>=0;--i) 
	    inv[i] = inv[i+1] * (i + 1) % P;
	for (int i=1;i<=n;++i)
		for (int j=0;j<=i;++j) {
			f[i][j] = f[i-1][j];
			if (j == 0) continue;
			f[i][j] += f[i][j-1] * (n-j+1) % P * C(n*k-i-(j-1)*(k-1)-1,k-2) % P;
			f[i][j] %= P;
		}
	cout << f[n][n] + (k == 1) << endl;
	return 0;
} 