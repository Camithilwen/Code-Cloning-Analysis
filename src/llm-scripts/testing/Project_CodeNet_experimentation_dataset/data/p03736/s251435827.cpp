#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=200010;
int n,Q,A,B,a[N],oo,s[N],f[N],ans;
struct bit
{
	int t[N];
	void rs()
	{
	    reset(t,127);oo=t[0];
	}
	void upd(int i,int x)
	{
		for(;i<=n;i+=i&-i) t[i]=min(t[i],x);
	}
	int get(int i)
	{
		int g=oo;
		for(;i;i-=i&-i) g=min(g,t[i]);
		return g;
	}
}T[2];
void add(int i,int x)
{
	T[0].upd(i,x-i);
	T[1].upd(n-i+1,i+x);
}
main()
{
    //freopen("C.inp","r",stdin);
	n=in,Q=in,A=in,B=in;
	forinc(i,1,Q) a[i]=in;
	forinc(i,2,Q) s[i]=s[i-1]+abs(a[i]-a[i-1]);
	T[0].rs();T[1].rs();
	add(B,abs(A-a[1]));
	add(A,abs(B-a[1]));
	ans=s[Q]+min(abs(A-a[1]),abs(B-a[1]));
	forinc(i,2,Q)
	{
		f[i]=min(T[0].get(a[i])+a[i],T[1].get(n-a[i]+1)-a[i])+s[i-1];
		add(a[i-1],f[i]-s[i]);
		ans=min(ans,f[i]+s[Q]-s[i]);
	}
	cout<<ans<<"\n";
}
