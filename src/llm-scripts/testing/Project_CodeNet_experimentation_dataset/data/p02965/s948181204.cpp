#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e6+10;
const ll mod=998244353;
ll inv(ll x){
    ll ans=1;
    for(ll i=mod-2;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
ll fact[mn];
ll ch(ll n,ll k){
    if(k<0||k>n)return 0;
    return fact[n]*inv(fact[k])%mod*inv(fact[n-k])%mod;
}
ll hail(ll k,ll n,ll m){
    m++;
    return ch(k+n-1,n-1)-n*ch(k+n-1-m,n-1)%mod;
}
int main()
{
    ll n,m,i;
    fact[0]=1;
    for(i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod;
    scanf("%lld%lld",&n,&m);
    ll ans=0;
    for(i=m%2;i<=min(n,m);i+=2){
        ans+=ch(n,i)*hail((3*m-i)/2,n,m-1)+(hail((3*m-i)/2,n,m)-hail((3*m-i)/2,n,m-1))*ch(n-1,i);
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}
