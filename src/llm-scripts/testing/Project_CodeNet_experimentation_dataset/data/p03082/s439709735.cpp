#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

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
    int n,x;
    cin>>n>>x;
    int s[n+1];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    s[n]=INF;
    sort(s,s+n);
    int crt=0;
    ll dp[x+1]={};
    for(int i=0;i<=x;i++){
        while(s[crt]<=i)crt++;
        if(crt==0){
            dp[i]=i;
            continue;
        }
        ll inv=modpow(crt,MOD-2);
        for(int j=0;j<crt;j++){
            dp[i]=(dp[i]+dp[i%s[j]])%MOD;
        }
        dp[i]=(dp[i]*inv)%MOD;
    }
    ll ans=dp[x];
    for(int i=2;i<=n;i++){
        ans=(ans*i)%MOD;
    }
    cout<<ans<<endl;
}
