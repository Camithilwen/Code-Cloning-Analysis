#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
const int N=200005;
const LL inf=1ll<<40;
int n,q,sta,stb;
int x[N];
struct tree
{
	LL mv1[N*4],mv2[N*4],tag[N*4];//mv1-> f[x]-x mv2 -> f[x]+x
	void pushup(int k)
	{
		mv1[k]=min(mv1[k<<1],mv1[k<<1|1]);
		mv2[k]=min(mv2[k<<1],mv2[k<<1|1]);
	}
	void setv(int k,LL v){tag[k]+=v;mv1[k]+=v;mv2[k]+=v;}
	void pushdown(int k)
	{
		if(!tag[k])return;
		setv(k<<1,tag[k]);setv(k<<1|1,tag[k]);
		tag[k]=0;
	}
	void build(int k,int l,int r)
	{
		tag[k]=0;
		if(l==r){mv1[k]=mv2[k]=inf;return;}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void upd(int k,int l,int r,int pos,LL v)
	{
		if(l==r){if(v<mv1[k]+l){mv1[k]=v-l;mv2[k]=v+l;}return;}
		int mid=(l+r)>>1;
		pushdown(k);
		if(mid>=pos)upd(k<<1,l,mid,pos,v);
		else upd(k<<1|1,mid+1,r,pos,v);
		pushup(k);
	}
	LL query1(int k,int l,int r,int ql,int qr)// query mv1
	{
		if((l>=ql&&r<=qr)||mv1[k]>=inf)return mv1[k];
		int mid=(l+r)>>1;LL res=inf;
		pushdown(k);
		if(mid>=ql)res=min(res,query1(k<<1,l,mid,ql,qr));
		if(mid<qr)res=min(res,query1(k<<1|1,mid+1,r,ql,qr));
		return res;
	}
	LL query2(int k,int l,int r,int ql,int qr)// query2 mv2
	{
		if((l>=ql&&r<=qr)||mv2[k]>=inf)return mv2[k];
		int mid=(l+r)>>1;LL res=inf;
		pushdown(k);
		if(mid>=ql)res=min(res,query2(k<<1,l,mid,ql,qr));
		if(mid<qr)res=min(res,query2(k<<1|1,mid+1,r,ql,qr));
		return res;
	}
	LL querya(int k,int l,int r)
	{
		if(l==r)return mv1[k]+l;
		int mid=(l+r)>>1;
		pushdown(k);
		return min(querya(k<<1,l,mid),querya(k<<1|1,mid+1,r));
	}
}t;
int Abs(int x){return x<0?-x:x;}
int input()
{
	int x=0,F=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')F=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*F;
}
int main()
{
	cin>>n>>q>>sta>>stb;
	for(int i=1;i<=q;i++)x[i]=input();
	x[0]=sta;
	t.build(1,1,n);
	t.upd(1,1,n,stb,0);
	for(int i=1;i<=q;i++)
	{
		LL minv=min(t.query1(1,1,n,1,x[i])+x[i],t.query2(1,1,n,x[i]+1,n)-x[i]);
		t.setv(1,Abs(x[i]-x[i-1]));
		t.upd(1,1,n,x[i-1],minv);
	}
	cout<<t.querya(1,1,n);
	return 0;
}
