#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

ll dp[201][100001];

int main(){
    int n,x;
    cin>>n>>x;
    ll s[n];
    rep(i,n)cin>>s[i];
    sort(s,s+n,greater<ll>());
    dp[0][x]=1;
    for(int i=0;i<n;++i){
        ll p=modpow(n-i,mod-2);
        for(int j=0;j<=x;++j){
            dp[i+1][j%s[i]]=(dp[i+1][j%s[i]]+dp[i][j]*p)%mod;
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(mod+1-p))%mod;
        }
    }
    ll ans=0;
    for(int i=0;i<=x;++i){
        ans=(ans+i*dp[n][i])%mod;
    }
    rep(i,n){
        ans=(ans*(i+1))%mod;
    }
    cout<<ans<<endl;
}
