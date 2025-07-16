// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=1000+10;
const int mod=1e9+7;
int qpow(int a,int b) { int c=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) c=1ll*c*a%mod;
	return c;
}

int n,a,b,c,d,dp[N][N];

int fac[N],ifac[N];
void init(int n) {
	fac[0]=1;
	for (int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for (int i=n;i;--i) ifac[i-1]=1ll*ifac[i]*i%mod;
}
int C(int n,int m) { return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod; }

int main() {
	init(1000);
	n=read(),a=read(),b=read(),c=read(),d=read();
	for (int i=0;i<=b;++i) dp[0][i]=1;
	for (int i=1;i<=n;++i)
		for (int j=a;j<=b;++j) {
			dp[i][j]=dp[i][j-1];
			for (int k=c;k<=d;++k) {
				if (i-j*k<0) break;
				dp[i][j]=(dp[i][j]+1ll*dp[i-j*k][j-1]*C(n-i+j*k,j*k)%mod
						 *fac[j*k]%mod*ifac[k]%mod*qpow(ifac[j],k))%mod;
			}
		}
	printf("%d\n",dp[n][b]);
	return 0;
}