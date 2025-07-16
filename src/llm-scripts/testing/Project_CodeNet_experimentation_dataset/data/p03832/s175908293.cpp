#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

struct Combination{
    vector<ll> fac,finv,inv;
    Combination(int mx){init(mx);}
    void init(int mx){
        fac.resize(mx+1);
        finv.resize(mx+1);
        inv.resize(mx+1);
        fac[0]=fac[1]=1;
        finv[0]=finv[1]=1;
        inv[1]=1;
        for(int i=2;i<=mx;i++){
            fac[i]=fac[i-1]*i%MOD;
            inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
            finv[i]=finv[i-1]*inv[i]%MOD;
        }
    }
    ll calc(int n,int k){
        return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
    }
};

ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1)res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}

int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    ll dp[n+1]={};
    dp[0]=1;
    Combination comb(n);
    for(int j=a;j<=b;j++){
        for(int i=n;i>=1;i--){
            for(int k=c;k<=i/j&&k<=d;k++){
                ll ce=comb.calc(n-(i-k*j),k*j)*comb.fac[k*j];
                ce%=MOD;
                ce*=comb.finv[k];
                ce%=MOD;
                ce*=modpow(comb.finv[j],k);
                ce%=MOD;
                dp[i]+=dp[i-k*j]*ce;
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[n]<<endl;
}