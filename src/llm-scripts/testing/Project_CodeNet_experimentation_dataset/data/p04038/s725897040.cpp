#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
int ad(int x,int y) { x+=y; return x>=mod?x-mod:x; }
int sb(int x,int y) { x-=y; return x<0?x+mod:x; }
int mu(int x,int y) { return 1ll*x*y%mod; }
int ksm(int a,int b) {
	int ans = 1;
	for(;b;b>>=1,a=mu(a,a))
		if(b&1) ans = mu(ans,a);
	return ans;
}
int fac[4000005],piv[4000005],n,k;
int GC(int a,int b) {
	if(a<b) return 0;
	return mu(fac[a],mu(piv[b],piv[a-b]));
}
int f[2005][2005];
int main() {
	scanf("%d%d",&n,&k);
	if(k==1) {
		puts("1"); return 0;
	}
	fac[0] = 1;
	for(int i=1;i<=n*k;i++) fac[i] = mu(fac[i-1],i);
	piv[n*k] = ksm(fac[n*k],mod-2);
	for(int i=n*k-1;i>=0;i--) piv[i] = mu(piv[i+1],i+1);
	f[0][0] = 1;
	for(int i=1;i<=n;i++) {
		f[i][0] = 1;
		for(int j=1;j<=i;j++) {
			f[i][j] = ad(f[i-1][j],mu(GC((n-i)+(n-j+1)*(k-1)-1,k-2),mu(f[i][j-1],n-j+1)));
		}
	}
	printf("%d",f[n][n]);
}