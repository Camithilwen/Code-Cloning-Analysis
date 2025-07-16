#include <cstdio>
typedef long long ll;
inline ll rd(){
    ll x=0,p=1;
    char a=getchar();
    while((a<48||a>57)&&a!='-')a=getchar();
    if(a=='-')p=-p,a=getchar();
    while(a>47&&a<58)x=(x<<1)+(x<<3)+(a&15),a=getchar();
    return x*p;
}
const int N=2002;
const ll mod=1e9+7;
inline ll fpow(ll b,ll p,ll mod){
	ll ans=1,tmp=b;
	while(p){
		if(p&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		p>>=1;
	}
	return ans;
}
int n,k;
ll fac[N*N],inv[N*N],f[N][N];
inline ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	fac[0]=1;
	n=rd(),k=rd();
	if(k==1)return puts("1"),0;
	for(int i=1;i<=4000000;i++)fac[i]=fac[i-1]*i%mod;
	f[0][0]=1;
	inv[4000000]=fpow(fac[4000000],mod-2,mod);
	for(int i=3999999;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mod;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+f[i][j-1]*(n-j+1)%mod*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod)%mod;
		}
	printf("%lld\n",f[n][n]);
    return 0;
}