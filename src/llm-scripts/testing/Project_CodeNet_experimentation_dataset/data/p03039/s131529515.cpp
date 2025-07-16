#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f
using namespace std;
template<class T>il read(T &x){
	int f=1;char k=getchar();x=0;
	for(;k>'9'||k<'0';k=getchar()) if(k=='-') f=-1;
	for(;k>='0'&&k<='9';k=getchar()) x=x*10+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x>=10) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
ll mul(ll a,ll b,ll mod){long double c=1.;return (a*b-(ll)(c*a*b/mod)*mod)%mod;}
it qpow(int x,int k,int mod){
	int res=1,bas=x;
	while(k){
		if(k&1) res=1ll*res*bas%mod;
		bas=1ll*bas*bas%mod,k>>=1;
	}
	return res;
}
const int N = 2e5+5,mod = 1e9+7;
it add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
it mul(int x,int y){return 1ll*x*y%mod;}
il inc(int &x,int y){x=add(x,y);}
int n,m,k,ans,fac[N],ifac[N];
it C(int n,int m){return mul(mul(ifac[n-m],ifac[m]),fac[n]);}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(m),read(k),fac[0]=1;
	for(ri i=1;i<=n*m;++i) fac[i]=mul(fac[i-1],i);
	ifac[n*m]=qpow(fac[n*m],mod-2,mod);
	for(ri i=n*m-1;i>=0;--i) ifac[i]=mul(ifac[i+1],i+1);
	for(ri i=1;i<=n-1;++i) inc(ans,mul(mul(mul(m,m),n-i),i));
	for(ri i=1;i<=m-1;++i) inc(ans,mul(mul(mul(n,n),m-i),i));
	print(mul(ans,C(n*m-2,k-2)));
	return 0;
}