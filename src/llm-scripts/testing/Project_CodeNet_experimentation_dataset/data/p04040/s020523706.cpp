#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll mod=1000000007;
ll modpow(ll x,ll y){
if(y==0)
  return 1;
  else if(y%2==0){
    ll z=modpow(x,y/2);
    return (z*z)%mod;
  }else{
  ll z=modpow(x,y/2);
    return (x*((z*z)%mod))%mod;
  }
}
ll H,W,A,B;
ll fac[200005];
ll rev[200005];
int main(){
cin>>H>>W>>A>>B;
  fac[0]=1;rev[0]=1;
  for(ll i=1;i<=200004;i++){
  fac[i]=(i*fac[i-1])%mod;
    rev[i]=modpow(fac[i],mod-2);
  }ll ans=0;
  for(ll i=B;i<W;i++){
  ll a=(rev[i]*((fac[H-A-1+i]*rev[H-A-1])%mod))%mod;
    ll b=(rev[W-1-i]*((fac[W+A-2-i]*rev[A-1])%mod))%mod;
    ans=(ans+(a*b)%mod)%mod;
  }cout<<ans<<endl;
  return 0;
}