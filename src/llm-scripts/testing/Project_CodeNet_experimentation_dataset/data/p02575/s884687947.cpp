#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<queue>
#include<bitset>
#include<cstdlib>
#include<set>
#include<unordered_map>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)
#define low(x) (x&(-x))
#define IL inline
#define reg register
#define LL long long
#define N 500010
#define MOD 998244353
#define MO 1000000007
#define INF 0x3f3f3f3f
using namespace std;

int T,n,m,i,j,k,y,z,pos,l,r;
LL Ans,x;
int a[N],b[N];
char c[N];

IL LL Min(LL a,LL b){return (a<b)?a:b;}
IL LL Max(LL a,LL b){return (a>b)?a:b;}

IL int read(){
	int p=0,f=1;	char	c=getchar();
	while (c<48||c>57)	{if (c=='-')	f=-1;	c=getchar();}
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p*f;
}

struct Segtree{
	struct Tree{
		int l,r;
		LL d,lz;
	}t[N*4];

	IL void Maketree(int x,int low,int high){
		int mid=(low+high)>>1;
		t[x].l=low;	t[x].r=high;
		if (low==high){t[x].d=a[low];	return;}
		Maketree(l(x),low,mid);	Maketree(r(x),mid+1,high);
		t[x].d=Min(t[l(x)].d,t[r(x)].d);
	}

	IL void Push(int x){
		LL p=t[x].lz;
		t[l(x)].d+=p;	t[r(x)].d+=p;
		t[l(x)].lz+=p;	t[r(x)].lz+=p;
		t[x].lz=0;
	}

	IL void Add(int x,int low,int high,LL val){
		reg int mid=(t[x].l+t[x].r)>>1;
		if (t[x].l==low && t[x].r==high){
			t[x].d+=val;	t[x].lz+=val;
			return;
		}
		if (t[x].lz) Push(x);
		if (high<=mid)	Add(l(x),low,high,val);
		else if (low>mid)	Add(r(x),low,high,val);
		else Add(l(x),low,mid,val),Add(r(x),mid+1,high,val);
		t[x].d=Min(t[l(x)].d,t[r(x)].d);
	}

	IL LL Query(int x,int low,int high){
		reg int mid=(t[x].l+t[x].r)>>1;
		if (t[x].l==low && t[x].r==high)	return t[x].d;
		if (t[x].lz) Push(x);
		if (high<=mid)	return Query(l(x),low,high);
		else if (low>mid)	return Query(r(x),low,high);
		else return Min(Query(l(x),low,mid),Query(r(x),mid+1,high));
	}
}T1,T2;

struct Tree{
	int l,r;
	LL d,lz;
}t[N*4];

int main(){
	#ifdef __Marvolo
	freopen("zht.in","r",stdin);
	freopen("zht.out","w",stdout);
	#endif
	n=read();	m=read();
	T1.Maketree(1,1,m);
	for (i=1;i<=m;i++)	a[i]=-i;
	T2.Maketree(1,1,m);
	for (i=1;i<=n;i++){
		l=read();	r=read();
		
		if (r<m){
			Ans=T2.Query(1,1,r);	x=T1.Query(1,r+1,r+1);
			if (Ans+r+1<x)	T1.Add(1,r+1,r+1,Ans+r+1-x),T2.Add(1,r+1,r+1,Ans+r+1-x);
		}

		T1.Add(1,l,r,INF);	T2.Add(1,l,r,INF);
		T1.Add(1,1,m,1);	T2.Add(1,1,m,1);
		
		Ans=T1.Query(1,1,m);
		if (Ans>=INF)	puts("-1");
		else printf("%lld\n",Ans);
	}
	return 0;
}