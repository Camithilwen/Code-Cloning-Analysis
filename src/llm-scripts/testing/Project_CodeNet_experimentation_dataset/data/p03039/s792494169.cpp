#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7, two = (mod+1)/2;
int n, m, k;
ll fac[N], inv[N];
ll powmod(ll a,ll b) 
{
	a %= mod;
	ll ans = 1;
	while(b)
	{
		if(b&1) ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}
void init(int n)
{
	fac[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
	inv[n] = powmod(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%mod;
}
ll comp(ll a,ll b)
{
	if(a<b||b<0||a<0) return 0;
	return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	ll ans = 0;
 	cin >> n >> m >> k;
 	init(n*m);
 	for(int i=1; i<n; i++)
 	{
		ll cur = 1ll*(n-i)*(n-i+1)%mod*m%mod*two%mod*m%mod;
		cur = cur*comp(n*m-2, k-2)%mod;
		ans = (ans + cur)%mod;
 	}
 	for(int i=1; i<m; i++)
 	{
		ll cur = 1ll*(m-i)*(m-i+1)%mod*n%mod*two%mod*n%mod;
		cur = cur*comp(n*m-2, k-2)%mod;
		ans = (ans + cur)%mod;
 	}
 	ans = (ans + mod)%mod;
 	cout << ans;
	return 0;
}
