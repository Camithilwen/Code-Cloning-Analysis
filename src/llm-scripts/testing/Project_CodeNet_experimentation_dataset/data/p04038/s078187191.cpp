// Etavioxy
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define il inline
#define rep(i,s,t) for(register int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(register int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pt(x) putchar(x)
using namespace std;
il int ci(){
	register char ch; int f=1;
	while(!isdigit(ch=getchar())) f=ch=='-'?-1:1;
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(x*10)+(ch^'0');
	return f*x;
}

const int mod = 1e9+7;
enum{N=2023};
il ll qpow(ll a,ll b){
	ll ans= 1;
	for(; b; b>>=1,a=a*a%mod) if( b&1 ){
		ans= ans*a%mod;
	} return ans;
}
il ll inv(ll x){ return qpow(x,mod-2); }
ll fac[N*N],Invf[N*N];
il void init_fac(int n){
	fac[0] = 1;
	rep(i,1,n) fac[i]=fac[i-1]*i%mod;
	Invf[n] = inv(fac[n]);
	rev_rep(i,n,1) Invf[i-1]=Invf[i]*i%mod;
}
il ll comp(ll n,ll m){
	if( n<m ) return 0;
	return fac[n]*Invf[m]%mod*Invf[n-m]%mod;
}

ll f[N][N];
int main(){
	int n = ci(), k = ci();
	if( k==1 ){
		puts("1");
		return 0;
	}
	init_fac(n*k);
	f[0][0] = 1;
	rep(i,1,n){
		f[i][0] = f[i-1][0];
		rep(j,1,i){
			f[i][j] = (f[i-1][j]+f[i][j-1]*(n-j+1)%mod*comp((n-i)+(n-j+1)*(k-1)-1,k-2))%mod;
		}
	}
	printf("%lld\n",(f[n][n]+mod)%mod);
	return 0;
}
