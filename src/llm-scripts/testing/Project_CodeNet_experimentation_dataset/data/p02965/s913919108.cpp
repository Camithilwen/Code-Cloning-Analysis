#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	cat tot = 1, dif = 0, fac_inv = 1, mod = 998244353;
	for(int i = 1; i < N; i++) {
		tot = tot * (3*M+i) % mod;
		fac_inv = fac_inv * i % mod;
	}
	vector<cat> prod_m1(N+3*M+1, 0), prod_m2(N+3*M+1, 0);
	prod_m1[0] = fac_inv;
	prod_m2[0] = fac_inv * pw(N-1, mod-2, mod) % mod;
	for(int i = 0; i < M; i++) {
		prod_m1[i+1] = prod_m1[i] * (i+N) % mod * pw(i+1, mod-2, mod) % mod;
		prod_m2[i+1] = prod_m2[i] * (i+N-1) % mod * pw(i+1, mod-2, mod) % mod;
	}
	for(int i = 0; i < M; i++) dif = (dif + prod_m2[i]) % mod;
	dif = dif * N % mod * (N-1) % mod;
	vector<cat> C(N+1, 0); // C(N, i)
	C[0] = 1;
	for(int i = 1; i <= N; i++) C[i] = C[i-1] * pw(i, mod-2, mod) % mod * (N-i+1) % mod;
	for(int i = M+1; i <= min(3*M, N); i++) if((M-i)%2 == 0)
		dif = (dif + prod_m1[(3*M-i)/2] * C[i]) % mod;
	cat ans = (tot - dif) * pw(fac_inv, mod-2, mod) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
