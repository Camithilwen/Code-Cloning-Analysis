//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = 1000000010;
const ll LOG = 25;
const int N = 2000 + 10;
int MOD;

int mul(int a, int b){
	return (a * 1ll * b) % MOD;
}

int add(int a, int b){
	a += b;
	a %= MOD;
	return a;
}

int dp[3 * N][3 * N], n;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> MOD;
	dp[0][0] = 1;
	for (int i = 1; i <= 3 * n; i++){
		for (int j = 0; j <= i / 2; j++){
			dp[i][j] = add(dp[i][j], dp[i - 1][j]);
			if (j != 0){
				if (i > 1) dp[i][j] = add(dp[i][j], mul(i - 1, dp[i - 2][j - 1]));
				if (i > 2) dp[i][j] = add(dp[i][j], mul(i - 2, mul(i - 1, dp[i - 3][j - 1])));
			}
		}
	}	
	int ans = 0;
	for (int i = 0; i <= n; i++){
		ans = add(ans, dp[3 * n][i]);
	}
	cout << ans;











	return 0;
}
