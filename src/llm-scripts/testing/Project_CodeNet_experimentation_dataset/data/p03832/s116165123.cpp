#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = 1005, mod = 1e9 + 7;
int a, b, c, d, gt[N], dp[N][N], n;

int pw(int x, int i){
	int b = 1;
	for(; i; i >>= 1, x = x * x % mod) if(i & 1) b = b * x % mod;
	return b;
}
int p(int n, int k){
	return (gt[n] * pw(gt[n - k], mod - 2) % mod) % mod;
}
main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> c >> d;
	gt[0] = 1;
	for(int i = 1; i <= n; ++i) gt[i] = gt[i - 1] * i % mod;
	for(int i = 0; i <= n; ++i) dp[0][i] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dp[i][j] = dp[i][j - 1]; if(a <= j && j <= b){
				for(int k = c; k <= d; ++k){
					if(i - j * k < 0) break;
					dp[i][j] = (dp[i][j] + dp[i - j * k][j - 1] * p(n - i + j * k, j * k) % mod * pw(gt[k], mod - 2) % mod * pw(pw(gt[j], k), mod - 2) % mod) % mod;
					dp[i][j] %= mod;
				}
			}
		}
	}
	cout << dp[n][n];
}