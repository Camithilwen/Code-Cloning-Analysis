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
typedef pair<int,int> pii;
const int N=100000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define maxd 1000000007
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
	int inv(int x) {return qpow(x,maxd-2);}

	int c(int n,int m)
	{
		if ((n<m) || (n<0) || (m<0)) return 0;
		return mul(mul(fac[n],invfac[m]),invfac[n-m]);
	}

	int math_init()
	{
		fac[0]=invfac[0]=1;
		rep(i,1,N) fac[i]=mul(fac[i-1],i);
		invfac[N]=inv(fac[N]);
		per(i,N-1,1) invfac[i]=mul(invfac[i+1],i+1);
	}
	#undef N
}
using namespace My_Math;
int n,A,B,C,D,f[1010][1010];

int main()
{
	n=read();A=read();B=read();C=read();D=read();
	math_init();
	f[0][0]=1;
	rep(i,1,B-A+1)
	{
		int t=i+A-1;
		rep(j,0,n)
		{
			f[i][j]=f[i-1][j];
			rep(k,C,D)
			{
				if (k*t>j) continue;
				int tmp=mul(f[i-1][j-k*t],c(n-j+k*t,k*t));
				tmp=mul(mul(tmp,invfac[k]),mul(qpow(invfac[t],k),fac[k*t]));
				f[i][j]=add(f[i][j],tmp);
			}
		}
	}
	printf("%d",f[B-A+1][n]);
	return 0;
}
		

