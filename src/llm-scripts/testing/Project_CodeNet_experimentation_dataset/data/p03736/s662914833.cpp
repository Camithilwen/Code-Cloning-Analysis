#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const long long oo=1e15;
struct Node
{
	Node *lch,*rch;
	int l,r;
	long long v1,v2,lz;
}*rt;
void update(Node *x)
{
	x->v1=min(x->lch->v1,x->rch->v1);
	x->v2=min(x->lch->v2,x->rch->v2);
}
void add(Node *x,long long v)
{
	x->lz+=v;
	x->v1+=v;
	x->v2+=v;
}
void down(Node *x)
{
	if(x->lz)
	{
		add(x->lch,x->lz);
		add(x->rch,x->lz);
		x->lz=0;
	}
}
int a,b;
Node *Build(int l,int r)
{
	Node *ret=new Node;
	ret->l=l;
	ret->r=r;
	ret->lz=0;
	if(l==r)
	{
		ret->v1=abs(l-a)-l;
		ret->v2=abs(l-a)+l;
		ret->lch=ret->rch=NULL;
		return ret;
	}
	int mid=(l+r)>>1;
	ret->lch=Build(l,mid);
	ret->rch=Build(mid+1,r);
	update(ret);
	return ret;
}
long long query(Node *x,int l,int r,int dir)
{
	if(l<=x->l&&r>=x->r)
	{
		if(dir==1)
			return x->v1;
		else
			return x->v2;
	}
	down(x);
	int mid=(x->l+x->r)>>1;
	long long ret=oo;
	if(l<=mid)
		ret=min(ret,query(x->lch,l,r,dir));
	if(mid<r)
		ret=min(ret,query(x->rch,l,r,dir));
	return ret;
}
void modify(Node *x,int p,long long v)
{
	if(x->l==x->r)
	{
		x->v1=min(x->v1,v-p);
		x->v2=min(x->v2,v+p);
		return ;
	}
	down(x);
	int mid=(x->l+x->r)>>1;
	if(p<=mid)
		modify(x->lch,p,v);
	else
		modify(x->rch,p,v);
	update(x);
}
long long findans(Node *x)
{
	if(x->l==x->r)
		return x->v1+x->l;
	down(x);
	return min(findans(x->lch),findans(x->rch)); 
} 
int main()
{
	int n,q,la,x;
	long long mi;
	scanf("%d%d%d%d",&n,&q,&a,&b);
	la=b;
	rt=Build(1,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		mi=min(query(rt,1,x,1)+x,query(rt,x,n,2)-x);
		add(rt,abs(x-la));
		modify(rt,la,mi);
		la=x;
	}
	printf("%lld",findans(rt));
	return 0;
}