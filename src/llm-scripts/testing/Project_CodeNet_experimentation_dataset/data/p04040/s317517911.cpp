#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=2e5+5;
const int mod=1e9+7;
ll fac[maxn]={1},ifac[maxn];
inline ll fastpow(ll a,ll b) {
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
	return ans;
}
inline void  init() {
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	ifac[maxn-1]=fastpow(fac[maxn-1],mod-2);
	for(int i=maxn-2;~i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}
inline ll C(ll n,ll m) {
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main() {
    init();
    ll h,w,a,b;cin>>h>>w>>a>>b;
    ll ans=0;
    for(int i=b+1;i<=w;i++) {
    	ans=(ans+C(h-1-a+i-1,i-1)*C(w-i+a-1,a-1)%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}