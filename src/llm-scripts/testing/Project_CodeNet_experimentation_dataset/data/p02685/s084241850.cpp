#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const ll MOD = 998244353;
static const int MAX = 500000+100;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll ModPow(ll a, ll cur=MOD-2) {
	ll r=1;
	while(cur) r=r*((cur%2)?a:1)%MOD,a=a*a%MOD,cur>>=1;
	return r;
}


int main(){
    ll N,M,K;
    cin>>N>>M>>K;
    /*
    先頭の選び方がM
    iが[0,K]で、
    先頭と同じ色のブロックの選び方はcomb(N-1,i)
    残りのブロックの色の選び方はM^(N-1-i);
    */

   ll ans = 0;
   COMinit();

   for(int i=0; i<=K; i++){
       ans += M*COM(N-1,i)%MOD*ModPow(M-1,N-1-i)%MOD;
   }

   cout<<ans%MOD<<endl;

    return 0;
}