#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 1000009
#define cbn(x,y) ((ll)fac[x]*inv[y]%mod*inv[(x)-(y)]%mod)
using namespace std;

int m,n,fac[N],inv[N];
int ksm(int x,int y){
	int z=1; for (; y; y>>=1,x=(ll)x*x%mod) if (y&1) z=(ll)z*x%mod;
	return z;
}
int main(){
	scanf("%d%d",&m,&n); if (m<n) swap(m,n);
	int i,ans=0;
	fac[0]=inv[0]=inv[1]=1;
	for (i=1; i<N; i++) fac[i]=(ll)fac[i-1]*i%mod;
	for (i=2; i<N; i++) inv[i]=mod-(ll)inv[mod%i]*(mod/i)%mod;
	for (i=2; i<N; i++) inv[i]=(ll)inv[i-1]*inv[i]%mod;
	for (i=1; i<=n; i++) ans=(ans+(ll)cbn(i<<1,i)*cbn(m+n-(i<<1),m-i))%mod;
	printf("%lld\n",((ll)ans*ksm(cbn(m+n,m)<<1,mod-2)+m)%mod);
	return 0;
}
