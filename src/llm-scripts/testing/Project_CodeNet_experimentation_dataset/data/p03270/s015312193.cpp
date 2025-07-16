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

const ll Mod = 998244353;
const int N = 4e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a*b) % Mod;
}
ll p2[N], C[N][N];

ll Solve(ll n, ll s){
	if(n == 0 && s == 0) return 1;
	if(s < 0) return 0;
	if(n <= 0) return 0;
	return C[s + n - 1][s];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	p2[0] = 1;
	for(int i = 1; i < N; i++) p2[i] = (p2[i - 1] << 1) % Mod;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++) C[i][j] = (j ? C[i - 1][j] + C[i - 1][j - 1] : 1) % Mod;
	}
	ll n, k;
	cin >> k >> n;
	for(int i = 2; i <= k+k; i++){
		ll res = 0;
		if(i & 1){
			ll t = (i <= k + 1 ? i / 2 : (k + k + 2 - i) / 2);
			for(int y = 0; y <= t; y++){
				res += mul(mul(p2[y], C[t][y]), Solve(k - t - t + y, n - y));
			}
		} else {
			ll t = (i <= k + 1 ? i / 2 : (k + k + 2 - i) / 2) - 1;
			for(int y = 0; y <= t; y++){
				res += mul(mul(p2[y], C[t][y]), Solve(k - t - t - 1 + y, n - y - 1));
				res += mul(mul(p2[y], C[t][y]), Solve(k - t - t - 1 + y, n - y));	
			}
		}
		cout << res%Mod << '\n';
	}
	return 0;
}
