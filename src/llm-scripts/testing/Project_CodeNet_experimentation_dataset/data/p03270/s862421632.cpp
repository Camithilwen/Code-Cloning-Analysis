#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 998244353
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
#define N 100010
ll fac[N],inv[N],ivf[N];
ll C(ll n,ll k){
    if(n<k)return 0;
  if(n<0||k<0)return 0;
    return fac[n]*ivf[n-k]%mod*ivf[k]%mod;
}
ll H(ll n,ll k){
    //if(k==0)return 1;
    return C(n+k-1,k);
}
ll P(ll n,ll k){
    return fac[n]*ivf[n-k]%mod;
}
ll po(ll x,ll y){
    ll res=1;
    for(;y;y>>=1){
	if(y&1)res=res*x%mod;
	x=x*x%mod;
    }
    return res;
}
ll solve(ll a,ll b,ll n){
    ll res=0;
    for(ll p=0;p<=b;p++){
	ll cur=C(b,p)*po(2,p)%mod;
	mul(cur,H(a+p,n-p));
	mad(res,cur);
    }
  //cout<<"#"<<a<<" "<<b<<" "<<n<<" "<<res<<endl;
    return res;
}
int main(){
    fac[0]=ivf[0]=inv[1]=1;
    for(int i=1;i<N;i++){
	if(i>1)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	fac[i]=fac[i-1]*i%mod;
	ivf[i]=ivf[i-1]*inv[i]%mod;
    }
  ll k,n; cin>>k>>n;
  for(ll i=2;i<=2*k;i++){
      ll a,b;
      a=abs(k-i+1);
      b=(k-a)/2;
      ll ans=solve(a,b,n);
      if(i%2==0){
	  mad(ans,solve(a,b,n-1));
      }
      if(ans<0)ans+=mod;
      cout<<ans<<endl;
  }
  return 0;
}

