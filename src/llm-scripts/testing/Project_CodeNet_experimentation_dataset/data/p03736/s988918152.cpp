#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ; 
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 2e5 + 5 ; 
const ll inf = 1e17 + 7 ;
using namespace std ;

int n, m, A, B, x[N] ;
ll bit[2][2][N], dist[N], f[2][N] ;

void put(int cx, int cy, int x, ll y) {
	for ( ; x <= n ; x += x & (- x)) bit[cx][cy][x] = min(bit[cx][cy][x], y) ;
}

ll get(int cx, int cy, int x) {
	ll res = inf ;
	for ( ; x ; x -= x & (- x)) res = min(res, bit[cx][cy][x]) ;
	return res ;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &A, &B) ;
	rep(i, 1, m) scanf("%d", &x[i]) ;
	rep(i, 0, 1) rep(j, 0, 1) rep(k, 1, n) bit[i][j][k] = inf ;
	rep(i, 2, m) dist[i] = dist[i - 1] + abs(x[i] - x[i - 1]) ;
	f[0][0] = abs(B - x[1]), f[1][0] = abs(A - x[1]) ;
	put(0, 0, A, f[0][0] - dist[1] - A), put(0, 1, n - A + 1, f[0][0] - dist[1] + A) ;
	put(1, 0, B, f[1][0] - dist[1] - B), put(1, 1, n - B + 1, f[1][0] - dist[1] + B) ;
	rep(i, 1, m - 1) {
		f[0][i] = min(get(1, 0, x[i + 1]) + dist[i] + x[i + 1], get(1, 1, n - x[i + 1] + 1) + dist[i] - x[i + 1]) ;
		f[1][i] = min(get(0, 0, x[i + 1]) + dist[i] + x[i + 1], get(0, 1, n - x[i + 1] + 1) + dist[i] - x[i + 1]) ;
		put(0, 0, x[i], f[0][i] - dist[i + 1] - x[i]), put(0, 1, n - x[i] + 1, f[0][i] - dist[i + 1] + x[i]) ;
		put(1, 0, x[i], f[1][i] - dist[i + 1] - x[i]), put(1, 1, n - x[i] + 1, f[1][i] - dist[i + 1] + x[i]) ;
	}
	ll ans = inf ;
	rep(i, 0, m - 1) ans = min(ans, min(f[0][i], f[1][i]) + dist[m] - dist[i + 1]) ;
	printf("%lld\n", ans) ;
	return 0 ;
}