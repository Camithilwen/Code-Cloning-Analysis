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
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 100100;
const int LOG = 17;
int n, L, q;
int Q[N][2];
int ANS[N];
int a[N];
int b[LOG][N];

void solve() {
	int p = 0;
	for (int i = 0; i < n; i++) {	
		while(p + 1 < n && a[p + 1] - a[i] <= L) p++;
		b[0][i] = p;
	}
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i < n; i++)
			b[k + 1][i] = b[k][b[k][i]];
	for (int i = 0; i < q; i++) {
		int v = Q[i][0], u = Q[i][1];
		if (v > u) continue;
		int ans = 0;
		for (int k = LOG - 1; k >= 0; k--) {
			if (b[k][v] < u) {
				v = b[k][v];
				ans += 1 << k;
			}
		}
		ANS[i] = ans + 1;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d%d", &L, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &Q[i][0], &Q[i][1]);
		Q[i][0]--;
		Q[i][1]--;
	}
	solve();
	for (int i = 0; i < q; i++) {
		Q[i][0] = n - 1 - Q[i][0];
		Q[i][1] = n - 1 - Q[i][1];
	}
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		a[i] *= -1;
	solve();
	for (int i = 0; i < q; i++)
		printf("%d\n", ANS[i]);

	return 0;
}
