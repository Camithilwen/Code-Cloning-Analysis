#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 100010;
const int mod = 1e9+7;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m,TOT;

int G[16][16];

int f[(1<<15)+5][16];

int All[(1<<15)+5];

void Work(){
	REP(sta,0,(1<<n)-1)REP(i,1,n)f[sta][i]=-1000000000;f[1][1]=0;
	REP(sta,0,(1<<n)-1)
		REP(i,1,n)if((sta>>i-1)&1){
			REP(j,1,n)if(j!=i&&((sta>>j-1)&1)&&G[i][j])f[sta][i]=max(f[sta][i],f[sta^(1<<i-1)][j]+G[i][j]);
			for(int s=sta;s;s=(s-1)&sta)if(!((s>>i-1)&1))f[sta][i]=max(f[sta][i],f[sta^s][i]+All[s^(1<<i-1)]);
		}
	iout(TOT-f[(1<<n)-1][n]);
}

void Init(){
	read(n,m);
	REP(i,1,m){
		int u,v,w;
		read(u,v,w);
		G[u][v]=G[v][u]=w;
		TOT+=w;
	}
	REP(sta,0,(1<<n)-1){
		REP(i,1,n)if((sta>>i-1)&1)
			REP(j,i+1,n)if((sta>>j-1)&1)All[sta]+=G[i][j];
	}
}

int main(){
	Init();
	Work();
	return 0;
}
