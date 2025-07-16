#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=300005;

int n,s,a[MAXN];
ll ans=0,b[MAXN];
int dir=-1;
void work(int l,int r)
{
	if(a[l]>s)ans+=a[r]-s;
	else if(a[r]<s)ans+=s-a[l];
	else if(b[l]>=b[r])
	{
		if(dir!=0)ans+=a[r]-a[l],dir=0;
		b[l]+=b[r];
		work(l,r-1);
	}
	else
	{
		if(dir!=1)ans+=a[r]-a[l],dir=1;
		b[r]+=b[l];
		work(l+1,r);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(s);
	for(int i=1;i<=n;++i)readint(a[i]),readint(b[i]);
	work(1,n);
	printf("%lld\n",ans);
	return 0;
}