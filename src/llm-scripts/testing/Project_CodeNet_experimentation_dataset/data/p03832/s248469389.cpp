#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD=1e9+7;

#define MAX 1000001
long fac[MAX], finv[MAX], inv[MAX];

void fact() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; ++i){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long comb(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}



int main(){
    ios::sync_with_stdio(false);
    fact();
    ll N,A,B,C,D;
    cin>>N>>A>>B>>C>>D;
    vector<vector<ll>> g(1001, vector<ll>(1001, -1));
    //G(i,a)はi人のグル×aの作り方
    function<ll(ll,ll)> G = [&](ll i,ll a){
        if(a<=1)return 1LL;
        else if(g[i][a]!=-1)return g[i][a];
        else return g[i][a]=(((G(i,a-1)*comb(i*a,i))%MOD)*modinv(a,MOD))%MOD;
    };
    vector<vector<ll>> dp(B+1, vector<ll>(N+1, -1));
    //F(a,x)はa人以上B人以下のグループのみを使ってx人を分ける場合の数
    function<ll(ll,ll)> F = [&](ll a, ll x){
        if(x==0)return 1LL;
        else if(dp[a][x]!=-1)return dp[a][x];
        else if(a==B){
            if(x%B==0&&C<=(x/B)&&(x/B)<=D)return dp[B][x]=G(B,x/B);
            else return dp[B][x]=0;
        }
        else{
        //Fa==0
        ll ret=F(a+1,x);
        //FaがCからD
        for(ll i=C;i<=D&&x-i*a>=0;++i){
            ret+=(((F(a+1,x-i*a)*G(a,i))%MOD)*comb(x,i*a))%MOD;
            ret%=MOD;
        }
        return dp[a][x]=ret;}
    };
    cout<<F(A,N)<<endl;


    return 0;
}
