#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

ll Mod = 998244353;
const int N = 2e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

ll dp[3 * N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n >> Mod;

	dp[0][0] = 1;
	for(int i = 1; i <= 3*n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = dp[i - 1][j];
			if(j){
				if(2 <= i) dp[i][j] += mul(i - 1, dp[i - 2][j - 1]);
				if(3 <= i) dp[i][j] += mul(mul(i - 2, i - 1), dp[i - 3][j - 1]);
			}
			dp[i][j] %= Mod;
		}
	}

	ll ans = 0;
	for(int i = 0; i <= n; i++) ans += dp[3 * n][i];
	cout << ans % Mod << '\n';
	return 0;
}
