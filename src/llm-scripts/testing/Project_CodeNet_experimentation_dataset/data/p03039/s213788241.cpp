#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
	ll n,m,k;
	cin>>n>>m>>k;
    COMinit();
    ll ans=0;
    for(ll i=1;;i++){
    	if(n-i==0){
    		break;
    	}
    	ll cnt=COM(n*m-2,k-2);
    	cnt*=m*m;
    	cnt%=inf;
    	cnt*=i*(n-i);
    	cnt%=inf;
    	ans+=cnt;
    	ans%=inf;
    }
    for(ll i=1;;i++){
    	if(m-i==0){
    		break;
    	}
    	ll cnt=COM(n*m-2,k-2);
    	cnt*=n*n;
    	cnt%=inf;
    	cnt*=i*(m-i);
    	cnt%=inf;
    	ans+=cnt;
    	ans%=inf;
    }    
    cout <<ans;
	// your code goes here
	return 0;
}