#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;
#define N 1010
int MOD = 1000000007;
int fac[N+1];
int inv[N+1];
ll bitpow(ll x,ll n){
    ll ans = 1;
    while(n > 0){
        if(n%2 == 1) ans = ans * x % MOD;
        x = x * x %MOD;
        n = n >> 1;
    }
    return ans;
}
ll COM(ll n,ll k){
    return fac[n]*inv[k]%MOD*inv[n-k]%MOD;
}
int dp[1010][1010] = {0};
signed main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1;i <= N;i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = bitpow(fac[i],MOD-2)%MOD;
    }
    dp[a-1][0] = 1;
    for(int i = a;i <= b;i++){
        for(int j = 0;j <= n;j++){
            dp[i][j] = dp[i-1][j];
            for(int k = c;k <= d;k++){
                if(j-i*k < 0 || i*k > n)break;
                dp[i][j] += dp[i-1][j-i*k] * fac[n-(j-i*k)] %MOD * inv[n-(j-i*k) - i*k] %MOD * inv[k]%MOD * bitpow(inv[i],k)%MOD;
                dp[i][j] %= MOD;
                // if(i == 3){
                //     //cerr << "j : dp[i-1][j-i*k] : fac[n-(j-i*k)] : inv[n-i*k] : inv[k] : bitpow(inv[i],k)" << endl;
                //     //cerr << j << " " << dp[i-1][j-i*k] <<  " : " << fac[n-(j-i*k)]<<  " : "<< inv[n-i*k] <<  " : "<<  inv[k] <<  " : "<<  bitpow(inv[i],k);
                //     //cerr << endl;
                //  }
            }
        }
    }
    cout << dp[b][n] << endl;




    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d
// rm -r -f test;oj dl http://arc067.contest.atcoder.jp/tasks/arc067_c