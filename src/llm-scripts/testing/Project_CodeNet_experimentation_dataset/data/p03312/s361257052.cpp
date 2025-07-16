#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=200000+100;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u],v=sq[i].to;i;i=sq[i].nxt,v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

namespace My_Math{
	#define N 100000

	int fac[N+100],invfac[N+100];

	int add(int x,int y) {return x+y>=maxd?x+y-maxd:x+y;}
	int dec(int x,int y) {return x<y?x-y+maxd:x-y;}
	int mul(int x,int y) {return 1ll*x*y%maxd;}
	ll qpow(ll x,int y)
	{
		ll ans=1;
		while (y)
		{
			if (y&1) ans=mul(ans,x);
			x=mul(x,x);y>>=1;
		}
		return ans;
	}
	int getinv(int x) {return qpow(x,maxd-2);}

	int C(int n,int m)
	{
		if ((n<m) || (n<0) || (m<0)) return 0;
		return mul(mul(fac[n],invfac[m]),invfac[n-m]);
	}

	void math_init()
	{
		fac[0]=invfac[0]=1;
		rep(i,1,N) fac[i]=mul(fac[i-1],i);
		invfac[N]=getinv(fac[N]);
		per(i,N-1,1) invfac[i]=mul(invfac[i+1],i+1);
	}
	#undef N
}
using namespace My_Math;

int n,a[N];
ll sum[N];

ll calc(int l,int r) {return sum[r]-sum[l-1];}

int main()
{
	n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) sum[i]=sum[i-1]+a[i];
	int l=1,r=3;
	ll ans=1e18;
	rep(i,2,n-2)
	{
		while ((l+2<=i) && (abs(calc(1,l)-calc(l+1,i))>abs(calc(1,l+1)-calc(l+2,i)))) l++;
		while ((r+2<=n) && (abs(calc(i+1,r)-calc(r+1,n))>abs(calc(i+1,r+1)-calc(r+2,n)))) r++;
		ll mx=0,mn=1e18,x;
		x=calc(1,l);mx=max(mx,x);mn=min(mn,x);
		x=calc(l+1,i);mx=max(mx,x);mn=min(mn,x);
		x=calc(i+1,r);mx=max(mx,x);mn=min(mn,x);
		x=calc(r+1,n);mx=max(mx,x);mn=min(mn,x);
		ans=min(ans,mx-mn);
	}
	printf("%lld\n",ans);
	return 0;
}
	

