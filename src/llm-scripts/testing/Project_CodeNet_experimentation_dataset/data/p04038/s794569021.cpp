//                             In The Name Of Allah
#include <bits/stdc++.h>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
#define ld long double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

const int N = 4e6 + 100, T = 2e3 + 100, OO = 1e12 + 10, M = 1e9 + 7, P = 49157, sq = 360, lg = 30;
typedef pair <int, int> pii;
int dp[T][T];
int fac[N], inv[N];
 
int pw(int x, int y) {
	if(y == 0)
		return 1;
	int cnt = pw(x, y / 2);
	cnt = (cnt * cnt) % M;
	cnt = (cnt * (y % 2 == 1 ? x : 1)) % M;
	return cnt;
}
 
void prepro() {
	fac[0] = 1;
	for(int i = 1; i <= N - lg; i++) 
		fac[i] = (fac[i - 1] * i) % M;
	inv[N - lg] = pw(fac[N - lg], M - 2);
	for(int i = N - lg - 1; i > -1; i--) 
		inv[i] = (inv[i + 1] * (i + 1)) % M;
}
 
int c(int x, int y) {
	if(x == y || y == 0)
		return 1;
	return ((fac[x] * inv[y] % M) * inv[x - y]) % M;
}

int32_t main() {
	use_fast;
	prepro();
	int n, k;
	cin >> n >> k;
	if(k == 1)
		return cout << 1, 0;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j >= 1; j--) 
			dp[i][j] = (dp[i][j + 1] + (dp[i - 1][j - 1] * i) % M * c(i * k - 1 - j, k - 2)) % M;
		dp[i][0] = dp[i][1];
	}
	cout << dp[n][0] << endl;
	return 0;
} 	
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/