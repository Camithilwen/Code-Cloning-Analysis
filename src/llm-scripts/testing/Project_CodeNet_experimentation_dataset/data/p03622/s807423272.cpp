#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

typedef long long LL;
const int MOD=998244353;
const int N=2000005;

LL fac[N],inv[N];

void upd(LL &x,LL v) {
	x+=v; (x>=MOD)?(x-=MOD):0;
}

void pre() {
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	rep(i,2,N-1) {
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	}
	rep(i,2,N-1) inv[i]=inv[i]*inv[i-1]%MOD;
}

LL ksm(LL x,LL dep) {
	LL res=1;
	for (;dep;dep>>=1) {
		(dep&1)?(res=res*x%MOD):0;
		x=x*x%MOD;
	}
	return res;
}

LL C(int n,int m) {
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}

int main(void) {
	pre(); int n,m;
	scanf("%d%d",&n,&m);
	if (n>m) std:: swap(n,m);
	LL ans=0;
	rep(i,1,n) upd(ans,C(i+i,i)*C(n+m-i*2,n-i)%MOD);
	ans=ans*ksm(C(n+m,n)*2%MOD,MOD-2)%MOD;
	upd(ans,m); printf("%lld\n", ans);
	return 0;
}