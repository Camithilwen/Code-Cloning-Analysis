#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

int n,q,sta,stb,x[maxn];
ll s[maxn];

struct Fenwick_Tree {
	int rev;
	ll s[maxn];
	Fenwick_Tree(int _rev=0){ rev=_rev;}
	inline void Clear(){ memset(s,63,sizeof(s));}

	inline void Add(int x,ll d){ for(x=rev?n-x+1:x;x<=n;x+=x&(-x))chkmin(s[x],d);}

	inline ll Sum(int x){ ll res=1ll<<60; for(x=rev?n-x+1:x;x;x-=x&(-x))chkmin(res,s[x]); return res;}
}A(0),B(1);

inline void init()
{
	n=read();q=read(); sta=read(); stb=read();
	REP(i,1,q)x[i]=read();
}

ll dp[maxn];
ll ans=1ll<<60;

inline void doing()
{
	A.Clear(); B.Clear();
	x[0]=sta; 
	REP(i,2,q)s[i]=s[i-1]+abs(x[i]-x[i-1]);
	dp[0]=abs(x[1]-stb); A.Add(sta,dp[0]-sta); B.Add(sta,dp[0]+sta);
	REP(i,1,q)
	{
		dp[i]=s[i]+min(x[i+1]+A.Sum(x[i+1]) , -x[i+1] + B.Sum(x[i+1]));
		A.Add(x[i],-s[i+1]-x[i]+dp[i]); B.Add(x[i],-s[i+1]+x[i]+dp[i]);
		chkmin(ans,dp[i]+s[q]-s[i+1]);
	}
}

int main()
{
	init();
	doing();
	swap(sta,stb); doing();
	printf("%lld\n",ans);
	return 0;
}

