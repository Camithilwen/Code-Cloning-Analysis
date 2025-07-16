#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=long long;
using P=pair<int,int>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-9;
const ll MOD=1000000007LL;
vector<ll> f,fi;
ll mpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*x%MOD;
        }
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
ll ncr(ll n,ll r){
    if(n<r)return 0;
    if(r==0)return 1;
    return f[n]*fi[r]%MOD*fi[n-r]%MOD;
}
int main(){
    int n;cin>>n;
    f.resize(n+10,0);
    fi.resize(n+10,0);
    f[0]=1;
    for(ll i=1;i<=n;i++)f[i]=f[i-1]*i%MOD;
    fi[n]=mpow(f[n],MOD-2LL);
    for(ll i=n-1;i>=0;i--)fi[i]=fi[i+1]*(i+1)%MOD;
    vector<vector<ll>> dp(n+10,vector<ll>(n+10,0));
    int a,b,c,d;cin>>a>>b>>c>>d;
    dp[a-1][0]=1;
    for(int i=a;i<=b;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
            ll s=1;
            for(int k=1;k<c;k++)s=s*ncr(n-j+i*k,i)%MOD;
            for(int k=c;k<=d;k++){
                if(j-i*k<0)break;
                s=s*ncr(n-j+i*k,i)%MOD;
                dp[i][j]+=dp[i-1][j-i*k]*s%MOD*fi[k]%MOD;
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[b][n]<<endl;
}
