#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int dm = 1 << 16;
char dn[dm], * di = dn;
inline void putint(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}

const ll mod = 998244353;
ll modpow(ll A, ll B) {
	ll kotae = 1;
	while (B > 0) {
		if (B & 1) kotae = kotae * A % mod;
		A = A * A % mod;
		B >>= 1;
	}
	return kotae;
}

const int IMAX = 4000;
int fac[IMAX + 1], ifac[IMAX + 1];
inline ll comb(int A, int B) {
	return fac[A] * ifac[B] % mod * ifac[A - B] % mod;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);



	int K, N;
	scanf("%d", &K);
	scanf("%d", &N);

	if (K == 1) {
		printf("0");
		return 0;
	}

	fac[0] = 1;
	rep1(i, IMAX) fac[i] = (ll)fac[i - 1] * i % mod;
	ifac[IMAX] = modpow(fac[IMAX], mod - 2);
	for (int i = IMAX; i > 0; i--) ifac[i - 1] = (ll)ifac[i] * i % mod;
	int H[1001];
	rep(i, 1001) {
		if (N >= 2 * i) {
			if (i & 1) H[i] = (ll)-fac[N + K - 1 - 2 * i] * ifac[N - 2 * i] % mod;
			else H[i] = (ll)fac[N + K - 1 - 2 * i] * ifac[N - 2 * i] % mod;
		}
	}

	int kotae[1001];
	rep1(i, (K + 1) / 2) {
		ll tmp = 0;
		for (int j = 0; j <= i && N >= j * 2; j++) {
			tmp += (ll)ifac[j] * ifac[i - j] % mod * H[j] % mod;
		}
		kotae[i] = (tmp % mod * ifac[K - 1] % mod * fac[i] % mod + mod) % mod;
	}

	rep1(i, (K + 1) / 2 - 1) {
		putint(kotae[i]);
		putint(kotae[i]);
	}
	putint(kotae[(K + 1) / 2]);
	if (!(K & 1)) {
		putint(kotae[(K + 1) / 2]);
		putint(kotae[(K + 1) / 2]);
	}
	for (int i = (K + 1) / 2 - 1; i >= 1; i--) {
		putint(kotae[i]);
		putint(kotae[i]);
	}

	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}