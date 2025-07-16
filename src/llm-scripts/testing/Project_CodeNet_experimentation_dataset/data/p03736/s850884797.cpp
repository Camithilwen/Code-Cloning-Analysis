#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define cmin(a,b) a=min(a,b)
using namespace std;
typedef long long ll;
ll n,Q,A,B;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=2e5+50,V=N<<2,inf=1e15;
ll X[N];
struct Segment_tree
{
	ll vmi[V],ami[V],bmi[V],tag[V];
	void cover(ll rt,ll w)
	{
		vmi[rt]+=w;ami[rt]+=w;bmi[rt]+=w;tag[rt]+=w;
	}
	void mdown(ll rt)
	{
		if(tag[rt])
		{
			cover(ls,tag[rt]);cover(rs,tag[rt]);
			tag[rt]=0;
		}
	}
	void mup(ll rt)
	{
		vmi[rt]=min(vmi[ls],vmi[rs]);
		ami[rt]=min(ami[ls],ami[rs]);
		bmi[rt]=min(bmi[ls],bmi[rs]);
	}
	void build(ll rt,ll l,ll r)
	{
		if(l==r)
		{
			vmi[rt]=ami[rt]=bmi[rt]=inf;return ;
		}
		ll mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		mup(rt);
	}
	void chg(ll rt,ll l,ll r,ll x,ll w)
	{
		if(l==r)
		{
			vmi[rt]=w;ami[rt]=w-l;bmi[rt]=w+l;
			//printf("U%lld %lld\n",x,w);
			return ;
		}
		ll mid=(l+r)>>1;
		mdown(rt);
		if(mid>=x) chg(ls,l,mid,x,w);
		else chg(rs,mid+1,r,x,w);
		mup(rt);
	}
	ll qry(ll rt,ll l,ll r,ll x,ll y,ll typ)
	{
		if(l>=x&&r<=y)
		{
			if(typ==0) return ami[rt];
			else return bmi[rt];
		}
		ll mid=(l+r)>>1,ras=inf;
		mdown(rt);
		if(mid>=x) cmin(ras,qry(ls,l,mid,x,y,typ));
		if(mid<y) cmin(ras,qry(rs,mid+1,r,x,y,typ));
		return ras; 
	}
}sgt;
int main()
{
	ll i,val;
	n=rd();Q=rd();A=rd();B=rd();	
	sgt.build(1,1,n);
	sgt.chg(1,1,n,B,0);
	X[0]=A;
	for(i=1;i<=Q;i++) X[i]=rd();
	for(i=1;i<=Q;i++)
	{
		val=min(sgt.qry(1,1,n,1,X[i],0)+X[i],sgt.qry(1,1,n,X[i],n,1)-X[i]);
		//printf("P%lld %lld %lld %lld\n",i,val,sgt.qry(1,1,n,1,X[i],0),sgt.qry(1,1,n,X[i],n,1));
		sgt.cover(1,abs(X[i]-X[i-1]));
		sgt.chg(1,1,n,X[i-1],val);
	}
	printf("%lld",sgt.vmi[1]);
	return 0;
}