#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e3 + 5;
const ll mod = 1e9 + 7;

ll mul(ll a, ll b){
	return (a * b) % mod;
}
ll power(ll x, ll y){
	if(y == 1){
		return x;
	} else {
		ll tmp = power(x, y/2);
		if(y & 1){
			return mul(mul(tmp, tmp), x);
		} else {
			return mul(tmp, tmp);
		}
	}
}

ll n, a, b, c, d, dp[N][N];
ll fac[N], rev[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b >> c >> d;
	fac[0] = 1;
	rev[0] = power(fac[0], mod - 2);
	for(int i = 1; i <= n; i++){
		fac[i] = (fac[i - 1] * i) % mod;
		rev[i] = power(fac[i], mod - 2);
	}
	for(int i = a - 1; i <= b; i++){
		dp[0][i] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = a; j <= b; j++){
			dp[i][j] = dp[i][j - 1];
			for(int k = c; k <= d && k * j <= i; k++){
				ll tmp = mul(mul(mul(fac[n - i + j * k], rev[n - i]), power(rev[j], k)), rev[k]);
				dp[i][j] = (dp[i][j] + mul(dp[i - j * k][j - 1], tmp)) % mod;
			}
		}
	}
	cout << dp[n][b];
}