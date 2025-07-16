#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll dp[1010];
ll F[1010], FI[1010];
ll n, a, b, c, d;

ll pow(ll a, ll b) { return b? pow(a * a % mod, b >> 1) * (b & 1? a : 1) % mod : 1; }

int main()
{
	ll i, j, k;
	
	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
	
	F[0] = FI[0] = 1;
	
	for(i=1; i<=n; i++){
		F[i] = F[i - 1] * i % mod;
		FI[i] = pow(F[i], mod - 2);
	}
	
	dp[0] = 1;
	
	for(i=a; i<=b; i++){
		for(j=n; j>=0; j--){
			for(k=c; k<=d && j-k*i>=0; k++){
				dp[j] = (dp[j] + dp[j - k * i] * pow(FI[i], k) % mod * FI[k]) % mod;
			}
		}
	}
	
	printf("%lld\n", dp[n] * F[n] % mod);
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////