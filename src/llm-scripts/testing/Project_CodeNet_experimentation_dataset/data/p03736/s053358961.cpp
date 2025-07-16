#include<bits/stdc++.h>
#define ls u*2
#define rs u*2+1
#define mid (l+r)/2
#define int long long
using namespace std;
const int N=3e5;
int n,m,s,t;
int x[N];
int bj[N*2],lmin[N*2],rmin[N*2];
inline int read(){
	char c=getchar();
	register int s=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}return s;
}
inline void pushdown(register int u){
	if(!bj[u])return ;
	bj[ls]+=bj[u];
	bj[rs]+=bj[u];
	lmin[ls]+=bj[u];
	rmin[ls]+=bj[u];
	lmin[rs]+=bj[u];
	rmin[rs]+=bj[u];
	bj[u]=0;
	return ;
}
void update(int u){
	lmin[u]=min(lmin[ls],lmin[rs]);
	rmin[u]=min(rmin[ls],rmin[rs]);
}
int query(int u,int l,int r,int L,int R)
{
	if(L>R)return 191919810889;
	if(L<=l&&R>=r){
		return lmin[u];
	}
	pushdown(u);
	int minn=1919191989881;
	if(L<=mid)minn=query(ls,l,mid,L,R);
	if(R>mid)minn=min(minn,query(rs,mid+1,r,L,R));
	update(u);
	return minn;
}
int ask(int u,int l,int r,int L,int R)
{
	if(L>R)return 191919818809;
	if(L<=l&&R>=r){
		return rmin[u];
	}
	pushdown(u);
	int minn=1919191988819;
	if(L<=mid)minn=ask(ls,l,mid,L,R);
	if(R>mid)minn=min(minn,ask(rs,mid+1,r,L,R));
	update(u);
	return minn;
}
void add(int u,int l,int r,int k,int summ){
	if(l==r){
		
		lmin[u]=min(lmin[u],summ-l);
		rmin[u]=min(rmin[u],summ+l);
	//	cout<<"hh:"<<rmin[u]<<endl;
		return ;
	}
	pushdown(u);
	if(k<=mid)add(ls,l,mid,k,summ);
	if(k>mid)add(rs,mid+1,r,k,summ);
	update(u);
}
int modify(int u,int l,int r){
	if(l==r){
		return rmin[u]-l;
	}
	pushdown(u);
	int minn=191919818880;
	minn=min(modify(ls,l,mid),modify(rs,mid+1,r));
	return minn;
}
signed main()
{
	n=read();m=read();s=read();t=read();
	x[0]=s;
	for(register int i=1;i<=m;i++){x[i]=read();}
	memset(lmin,10,sizeof(lmin));
	memset(rmin,10,sizeof(rmin));
	add(1,1,n,t,0);
	for(int i=1;i<=m;i++){
		int af=min(query(1,1,n,1,x[i])+x[i],ask(1,1,n,x[i],n)-x[i]);
//		cout<<af<<endl;
		bj[1]+=abs(x[i]-x[i-1]);
		lmin[1]+=abs(x[i]-x[i-1]);
		rmin[1]+=abs(x[i]-x[i-1]);
		add(1,1,n,x[i-1],af);
	}
	printf("%lld",modify(1,1,n));
	return 0;
}