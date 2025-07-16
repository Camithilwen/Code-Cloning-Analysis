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
	for(;k>='0'&&k<='9';k=getchar()) x=(x<<3)+(x<<1)+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x/10) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
ll mul(ll a,ll b,ll mod){long double c=1.;return (a*b-(ll)(c*a*b/mod)*mod)%mod;}
it qpow(int x,int m,int mod){
	int res=1,bas=x;
	while(m){
		if(m&1) res=(1ll*res*bas)%mod;
		bas=(1ll*bas*bas)%mod,m>>=1;
	}
	return res;
}
const int MAXN = 2e3+5,mod = 998244353;
int n,k,C[MAXN<<1][MAXN<<1],bit[MAXN<<1];
it add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
it mul(int x,int y){return 1ll*x*y%mod;}
il inc(int &x,int y){x=add(x,y);}
il Init(){
	C[0][0]=1,bit[0]=1;
	for(ri i=1;i<=4000;++i){
		C[i][0]=1;
		for(ri j=1;j<=i;++j) C[i][j]=add(C[i-1][j],C[i-1][j-1]);
		bit[i]=mul(bit[i-1],2);
	}
}
it Solve(int x,int y,int z){
	int res=0;
	for(ri i=0;i<=z&&i<=x;++i)
		if(y+i-1>=0) inc(res,mul(mul(C[x][i],C[y+z-1][i+y-1]),bit[i]));
	return res;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(k),read(n),Init();
	for(ri i=2;i<=2*k;++i){
		int cnt=0;
		for(ri j=1;j<=k;++j) cnt+=(i-j>=1&&i-j<=k);
		if(i&1) print(Solve(cnt>>1,k-cnt,n)),puts("");
		else print(add(Solve(cnt>>1,k-cnt,n-1),Solve(cnt>>1,k-cnt,n))),puts("");
	}
	return 0;
}