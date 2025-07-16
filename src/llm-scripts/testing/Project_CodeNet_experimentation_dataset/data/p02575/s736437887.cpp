#include <bits/stdc++.h>
using namespace std;

/*

dp[i][j]=dp[i-1][j]+1; (j<L[i-1] or R[i-1]<j)
dp[i][j]=dp[i-1][L[i-1]-1]+1+(j-(L[i-1]-1)) (L[i-1]<=j<=R[i-1])
*/

const int M=2e5+5;
const int INF=0x3f3f3f3f;

struct SegT
{
	struct TN
	{
		int mn,fi,add;
		void app_add(int v)
		{
			add+=v;
			mn+=v;
		}
		void app_set(int v) // arthimic
		{
			add=0;
			fi=v;
			mn=v;
		}
	}tn[M*4];
	int P,L,R,V;
	void push(int o,int l,int mi,int r)
	{
		if(tn[o].fi!=-1)
		{
			tn[o<<1].app_set(tn[o].fi);
			tn[o<<1|1].app_set(tn[o].fi+mi-l+1);
			tn[o].fi=-1;
		}
		if(tn[o].add)
		{
			tn[o<<1].app_add(tn[o].add);
			tn[o<<1|1].app_add(tn[o].add);
			tn[o].add=0;
		}
	}
	void pull(int o)
	{
		tn[o].mn=min(tn[o<<1].mn,tn[o<<1|1].mn);
	}
	void build(int o,int l,int r)
	{
		tn[o].mn=tn[o].add=0;
		tn[o].fi=-1;
		if(l==r)
		{
			if(l==0) tn[o].mn=tn[o].add=INF;
			return;
		}
		int mid=(l+r)>>1;
		build(o<<1,l,mid);
		build(o<<1|1,mid+1,r);
		pull(o);
	}
	void add(int o,int l,int r)
	{
		if(L<=l&&r<=R)
		{
			tn[o].app_add(1);
			return;
		}
		int mid=(l+r)>>1;
		push(o,l,mid,r);
		if(L<=mid) add(o<<1,l,mid);
		if(mid<R) add(o<<1|1,mid+1,r);
		pull(o);
	}
	void set(int o,int l,int r)
	{
		if(L<=l&&r<=R)
		{
			tn[o].app_set(V+l-L+1);
			return;
		}
		int mid=(l+r)>>1;
		push(o,l,mid,r);
		if(L<=mid) set(o<<1,l,mid);
		if(mid<R) set(o<<1|1,mid+1,r);
		pull(o);
	}
	int query(int o,int l,int r)
	{
		if(l==r) return tn[o].mn;
		int mid=(l+r)>>1;
		push(o,l,mid,r);
		if(P<=mid) return query(o<<1,l,mid);
		else return query(o<<1|1,mid+1,r);
	}
}segt;

int main()
{
	int h,w; scanf("%d%d",&h,&w);
	segt.build(1,0,w);
	int l,r;
	for(int i=0;i<h;i++)
	{
		scanf("%d%d",&l,&r);
		if(l!=1)
		{
			segt.L=1; segt.R=l-1;
			segt.add(1,0,w);
		}
		if(r!=w)
		{
			segt.L=r+1; segt.R=w;
			segt.add(1,0,w);
		}
		segt.P=l-1;
		segt.V=segt.query(1,0,w);
		segt.L=l; segt.R=r;
		segt.set(1,0,w);
		int ans=segt.tn[1].mn;
		printf("%d\n",ans>=INF ? -1 : ans);
	}
	return 0;
}