#include<cstdio>
#include<iostream>
using namespace std;
int h,w; 
int l[200010],r[200010];
struct tree{
	int l,r;
	long long tag,v;
}tr[2][4*200010];
void build(int i,int l,int r)
{
	tr[0][i].l=l,tr[0][i].r=r;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
void update(int i,int id)
{
	tr[id][i].v=min(tr[id][i<<1].v,tr[id][i<<1|1].v);
}
void build2(int i,int l,int r)
{
	tr[1][i].l=l,tr[1][i].r=r;
	
	if (l==r) {tr[1][i].v=-l;return;}
	int mid=(l+r)>>1;
	build2(i<<1,l,mid);
	build2(i<<1|1,mid+1,r);
	update(i,1);
}
void add(int i,long long x,int id)
{
	//if (id==0&&tr[id][i].l==2&&tr[id][i].l==tr[id][i].r)
	//	cout<<tr[id][i].v<<" "<<x<<" tree"<<endl;
	tr[id][i].v+=x;
	tr[id][i].tag+=x;
}
void pushdown(int i,int id)
{
	if (tr[id][i].tag)
	{
		add(i<<1,tr[id][i].tag,id);
		add(i<<1|1,tr[id][i].tag,id);
		tr[id][i].tag=0;
	}
}
void modify(int i,int l,int r,long long x,int id)
{
	int L=tr[id][i].l,R=tr[id][i].r;
	if (l>R) return;
	if (l<=L&&R<=r)
	{
		add(i,x,id);
		return;
	}
	pushdown(i,id);
	int mid=(L+R)>>1;
	if (l<=mid) modify(i<<1,l,r,x,id);
	if (r>mid) modify(i<<1|1,l,r,x,id);
	update(i,id); 
}
long long query(int i,int l,int r,int id)
{
	int L=tr[id][i].l,R=tr[id][i].r;
	if (l>R) return 0;
	//cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<tr[id][i].v<<endl; 
	if (l<=L&&R<=r) return tr[id][i].v; 
	pushdown(i,id);
	int mid=(L+R)>>1;
	long long maxn=1e18;
	if (l<=mid) maxn=min(maxn,query(i<<1,l,r,id));
	if (r>mid) maxn=min(maxn,query(i<<1|1,l,r,id));
	return maxn;
}
int main()
{
	scanf("%d%d",&h,&w);
	for (int i=1;i<=h;i++)
		scanf("%d%d",&l[i],&r[i]);
	build(1,1,w);build2(1,1,w);
	for (int i=1;i<=h;i++)
	{
		long long other=min(0ll,r[i]+1+query(1,1,r[i],1)-query(1,r[i]+1,r[i]+1,0));
		modify(1,r[i]+1,r[i]+1,other,0);
		modify(1,r[i]+1,r[i]+1,other,1);
		
		modify(1,l[i],r[i],1e9,0);
		modify(1,l[i],r[i],1e9,1);
		
		modify(1,1,w,1,0);
		modify(1,1,w,1,1);
		long long ans=query(1,1,w,0);
		if (ans>=1e9) printf("-1\n");
		else printf("%d\n",ans);
	}
}
