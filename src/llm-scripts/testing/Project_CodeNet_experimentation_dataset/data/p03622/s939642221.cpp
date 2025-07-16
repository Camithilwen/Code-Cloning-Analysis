#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll Rev(ll x) {
	return bin_pow(x, MOD - 2);
}
ll W;

const int LOG = 20;
const int N = 1 << 20;
ll w[N];
int rev[N];

void initFFT() {
	for (ll x = 2;; x++) {
		ll y = x;
		for (int i = 1; i < LOG; i++)
			y = mult(y, y);
		if (y == MOD - 1) {
			W = x;
			break;
		}
	}
	w[0] = 1;
	for (int i = 1; i < N; i++)
		w[i] = mult(w[i - 1], W);
	rev[0] = 0;
	for (int mask = 1; mask < N; mask++) {
		int k = 0;
		while(((mask >> k) & 1) == 0) k++;
		rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (LOG - 1 - k));
	}
}

ll F[2][N];
void FFT(ll *A) {
	for (int i = 0; i < N; i++)
		F[0][rev[i]] = A[i];
	int t = 0, nt = 1;
	for (int lvl = 0; lvl < LOG; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < N; st += (len << 1))
			for (int i = 0; i < len; i++) {
				ll ad = mult(F[t][st + len + i], w[i << (LOG - 1 - lvl)]);
				F[nt][st + i] = add(F[t][st + i], ad);
				F[nt][st + len + i] = sub(F[t][st + i], ad);
			}
		swap(t, nt);
	}
	for (int i = 0; i < N; i++)
		A[i] = F[t][i];
}

ll f[N], rf[N];
ll a[N];

ll getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	initFFT();

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = Rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	for (int k = 0; k < N / 2; k++) {
		a[k] = mult(f[2 * k], mult(rf[k], rf[k]));
	}
	FFT(a);
	for (int i = 0; i < N; i++)
		a[i] = mult(a[i], a[i]);
	FFT(a);
	reverse(a + 1, a + N);
	ll rN = Rev(N);
	for (int i = 0; i < N; i++) {
		a[i] = mult(a[i], rN);
		a[i] = mult(a[i], mult(rf[2 * i], mult(f[i], f[i])));
		a[i] = sub(a[i], 1);
		a[i] = mult(a[i], (MOD + 1) / 2);
		a[i] += i;
	}

	int n, m;
	scanf("%d%d", &n, &m);
	if (n < m) swap(n, m);
	if (n == m) {
		printf("%lld\n", a[n]);
		return 0;
	}

	ll ans = 0;

	for (int k = 0; k <= m; k++) {
		int L = n - m + k - 1;
		ll p = getC(L + k, k);
		if (k > 0)
			p = sub(p, getC(L + k, k - 1));
		p = mult(p, getC(2 * (m - k), m - k));
		ans = add(ans, mult(p, add(L + 1, a[m - k])));
	}
	ans = mult(ans, mult(rf[n + m], mult(f[n], f[m])));
	printf("%lld\n", ans);

	return 0;
}
