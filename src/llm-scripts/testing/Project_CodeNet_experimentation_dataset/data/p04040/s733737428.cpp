#include<bits/stdc++.h>
using namespace std;
//#include<ext/rope>
//using namespace __gnu_cxx
//#include<ext/pb_ds/priority_queue.hpp>
//using namespace __gnu_pbds;
#define lowbit(x) (x&-x)
#define pb push_back
#define empb emplace_back
#define all(x) (x).begin(),(x).end()
#define clr(a,b) memset(a,b,sizeof(a))
#define caze(T) for(cin>>T;T;T--)
#define inf (1<<29)
#define Endl ('\n')
#define fi first
#define se second
#define db double
#define ldb long double
#define ll long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
inline char nc() {
	#define SZ 1000000
	static char buf[SZ], *p1, *p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
}
template<typename T>
inline int scan(T &x) {
	char c, sign=1; 
	while(!isdigit(c=nc())&&c!=EOF)if(c=='-')sign*=-1;
	if(c==EOF) return EOF;
	for(x = 0; isdigit(c); c = nc())
		x = (x<<1) + (x<<3) + (c&15);
	return x *= sign, 1;
}
template<typename T, typename...Args>
inline int scan(T &x, Args&...args) {
	return scan(x), scan(args...);
}
const int N=1<<18;
const int mod=1000000007;
int f[N],ivf[N];
int qp(int a,int b)
{
	int ret=1;
	for(;b;b>>=1,a=1LL*a*a%mod)
		if(b&1) ret=1LL*ret*a%mod;
	return ret;
}
int C(int n,int m){int ret=1LL*f[n]*ivf[n-m]%mod;return 1LL*ret*ivf[m]%mod;}
int go(int n,int m){return C(n+m-2,m-1);}
int main()
{
	f[0]=1;
	for(int i=1;i<N;++i)
		f[i]=1LL*f[i-1]*i%mod;
	ivf[N-1]=qp(f[N-1],mod-2);
	for(int i=N-2;~i;--i)
		ivf[i]=1LL*ivf[i+1]*(i+1)%mod;
	int n,m,a,b;
	while(cin>>n>>m>>a>>b)
	{
		int ans=0;
		for(int i=1;i<=n-a;++i)
		{
			int tp=1LL*go(i,b)*go(n-i+1,m-b)%mod;
			(ans+=tp)%=mod;
		}
		cout<<ans<<Endl;
	}
}