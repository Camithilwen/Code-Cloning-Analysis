//Solution by Tima
#include <bits/stdc++.h>
 
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
#define all(x) x.begin(), x.end()
 
using namespace std;    
const int N = int(1e5) + 12, mod = int(1e9)  + 7; 

int n,x,a[N],dp[202][N], obr[N];

ll modpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int calc(int i,int x){
	if(i > n) return x;
	if(dp[i][x] != -1) return dp[i][x];
	int res = 1ll * calc(i + 1, x) * (n - i) % mod;
	res += calc(i + 1, x % a[i]);
	if(res >= mod) res -= mod;
	return dp[i][x] = 1ll * res * obr[n - i + 1] % mod;
}

void solve(){
	scanf("%d%d", &n, &x);

	int f = 1;

	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		f = 1ll * f * i % mod;
		obr[i] = modpow(i, mod - 2);
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	printf("%d\n", 1ll * calc(1,x) * f % mod);

}

int main () {
	int T = 1;
	//scanf("%d", &T);

	while(T--){
		solve();
	}

return 0;
}