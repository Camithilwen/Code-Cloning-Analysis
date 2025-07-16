#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef std::pair<int,int> P;
#define mk std::make_pair
#define fr first
#define sc second
inline int in()
{
	int k=0;char ch=gt;bool p=1;
	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return p?k:-k;
}
const int N=2e5+5;
const ll inf=1ll<<60;
ll sum[N],ans=inf;int pos[N],n,Q;
inline void cmin(ll &x,ll y){if(x>y)x=y;}
struct Segment_tree
{
#define lc k<<1
#define rc k<<1|1
	ll val[N];int mi[N<<2];
	inline int cmp(const int &x,const int &y){return val[x]<val[y]?x:y;}
	void build(int l,int r,int k)
		{
			if(l==r)return val[mi[k]=l]=inf,void();
			int mid=l+r>>1;
			build(l, mid ,lc),build(mid+1,r,rc);
			mi[k]=cmp(mi[lc],mi[rc]);
		}
	void upd(int l,int r,int k,int p,ll v)
		{
			if(l==r)return cmin(val[l],v);
			int mid=l+r>>1;
			if(p<=mid)upd(l,mid,lc,p,v);
			else upd(mid+1,r,rc,p,v);
			mi[k]=cmp(mi[lc],mi[rc]);
		}
	int query(int L,int R,int l,int r,int k)
		{
			if(L<=l&&r<=R)return mi[k];
			int mid=l+r>>1;
			if(L> mid)return query(L,R,mid+1,r,rc);
			if(R<=mid)return query(L,R,l, mid ,lc);
			return cmp(query(L,R,l,mid,lc),query(L,R,mid+1,r,rc));
		}
}A,B,C;
inline int abs(int x){return x<0?-x:x;}
inline void solve(int x)
{
	for(int i=2;i<=Q;++i)sum[i]=sum[i-1]+abs(pos[i]-pos[i-1]);
	A.build(1,n,1),B.build(1,n,1),C.build(1,n,1);
	A.upd(1,n,1,x,0-x),B.upd(1,n,1,x,0+x),C.upd(1,n,1,x,0);
	for(int i=2;i<=Q;++i)
	{
		int le=A.query(1,pos[i],1,n,1),ri=B.query(pos[i],n,1,n,1);
		int res=abs(pos[i]-pos[i-1]);
		if(A.val[le]+pos[i]>B.val[ri]-pos[i])
		{
			C.upd(1,n,1,pos[i-1],B.val[ri]-pos[i]-res);
			A.upd(1,n,1,pos[i-1],B.val[ri]-pos[i]-res-pos[i-1]);
			B.upd(1,n,1,pos[i-1],B.val[ri]-pos[i]-res+pos[i-1]);
		}
		else
		{
			C.upd(1,n,1,pos[i-1],A.val[le]+pos[i]-res);
			A.upd(1,n,1,pos[i-1],A.val[le]+pos[i]-res-pos[i-1]);
			B.upd(1,n,1,pos[i-1],A.val[le]+pos[i]-res+pos[i-1]);
		}
	}
	cmin(ans,C.val[C.mi[1]]+sum[Q]);
}
int main()
{
	n=in(),Q=in()+1;int a=in(),b=in();
	for(int i=2;i<=Q;++i)pos[i]=in();
	pos[1]=a;solve(b);pos[1]=b;solve(a);
	return printf("%lld\n",ans),0;
}
