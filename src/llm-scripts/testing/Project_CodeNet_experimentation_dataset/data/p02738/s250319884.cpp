#include <cstdio>
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
ll mod;
int n;
ll powmod(ll a,ll b) {ll res=1;a%=mod; for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

ll ipw2[10100],ipw3[10100],fac[10100],fnv[10100];
int main() {
  scanf("%d%lld",&n,&mod);
	fac[0]=1;
	rep(i,1,10000) fac[i]=fac[i-1]*i%mod;
	rep(i,0,10000) fnv[i]=powmod(fac[i],mod-2),ipw2[i]=powmod(2,mod-1-i),ipw3[i]=powmod(3,mod-1-i);
	int s=0;
	rep(i,0,n+1) rep(j,0,n-i+1) s=(s+fnv[i]*fnv[j]%mod*fnv[3*n-3*i-2*j]%mod*ipw3[i]%mod*ipw2[j])%mod;
  printf("%d\n",s*fac[3*n]%mod);
}