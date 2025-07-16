#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define lc now<<1
#define rc now<<1|1
using namespace std;
inline int read()
{
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
inline void write(LL x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
inline void pr1(int x){write(x);putchar(' ');}
inline void pr2(LL x){write(x);putchar('\n');}
const LL inf=1e18;
const int MAXN=200005;
int n,D,a[MAXN];
struct node
{
	int p;LL c;
	node(){}
	node(int _p,LL _c){p=_p;c=_c;}
};
node _min(node u1,node u2){return u1.c<u2.c?u1:u2;}
struct segtree1
{
	node mn[2][MAXN*4];
	void buildtree(int now,int l,int r)
	{
		if(l==r){mn[0][now]=mn[1][now]=node(l,inf);return ;}
		int mid=(l+r)/2;
		buildtree(lc,l,mid);buildtree(rc,mid+1,r);
		mn[0][now]=mn[1][now]=_min(mn[0][lc],mn[1][rc]);
	}
	void modify(int now,int l,int r,int p,node c,int opt)
	{
		if(l==r){mn[opt][now]=c;return ;}
		int mid=(l+r)/2;
		if(p<=mid)modify(lc,l,mid,p,c,opt);
		else modify(rc,mid+1,r,p,c,opt);
		mn[opt][now]=_min(mn[opt][lc],mn[opt][rc]);
	}
	node qry(int now,int l,int r,int ql,int qr,int opt)//0 左边   1 右边 
	{
		if(l==ql&&r==qr)return mn[opt][now];
		int mid=(l+r)/2;
		if(qr<=mid)return qry(lc,l,mid,ql,qr,opt);
		else if(mid+1<=ql)return qry(rc,mid+1,r,ql,qr,opt);
		else return _min(qry(lc,l,mid,ql,mid,opt),qry(rc,mid+1,r,mid+1,qr,opt));
	}
}seg1,seg2;//1  未加入   2  加入 
struct segtree2
{
	node mn[MAXN*4];
	void buildtree(int now,int l,int r)
	{
		if(l==r){mn[now]=node(l,inf);return ;}
		int mid=(l+r)/2;
		buildtree(lc,l,mid);buildtree(rc,mid+1,r);
		mn[now]=_min(mn[lc],mn[rc]);
	}
	void pushup(int now,int l,int r)
	{
		int mid=(l+r)/2;
		mn[now]=_min(mn[lc],mn[rc]);
		node u1=seg1.mn[0][lc],u2=seg2.mn[1][rc];
//		u1=seg1.qry(1,1,n,l,mid,0),u2=seg2.qry(1,1,n,mid+1,r,1);
		mn[now]=_min(mn[now],node(u1.p,u1.c+u2.c));
		u1=seg1.mn[1][rc],u2=seg2.mn[0][lc];
//		u1=seg1.qry(1,1,n,mid+1,r,1),u2=seg2.qry(1,1,n,l,mid,0);
		mn[now]=_min(mn[now],node(u1.p,u1.c+u2.c));
	}
	void modify(int now,int l,int r,int p)
	{
		if(l==r){mn[now].c=inf;return ;}
		int mid=(l+r)/2;
		if(p<=mid)modify(lc,l,mid,p);
		else modify(rc,mid+1,r,p);
		pushup(now,l,r);
	}
}seg3;
int main()
{
	n=read();D=read();
	if(n==1)return puts("0"),0;
	for(int i=1;i<=n;i++)a[i]=read();
	seg1.buildtree(1,1,n);
	seg2.buildtree(1,1,n);
	seg3.buildtree(1,1,n);
	for(int i=2;i<=n;i++)
	{
		seg1.modify(1,1,n,i,node(i,(LL)-D*i+a[i]),0);
		seg1.modify(1,1,n,i,node(i,(LL)D*i+a[i]),1);
	}
	seg2.modify(1,1,n,1,node(1,(LL)-D*1+a[1]),0);
	seg2.modify(1,1,n,1,node(1,(LL)D*1+a[1]),1);
	
	seg3.modify(1,1,n,1);
	LL ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=seg3.mn[1].c;
		int u=seg3.mn[1].p;
		seg1.modify(1,1,n,u,node(u,inf),0);seg1.modify(1,1,n,u,node(u,inf),1);
		seg2.modify(1,1,n,u,node(u,(LL)-D*u+a[u]),0);seg2.modify(1,1,n,u,node(u,(LL)D*u+a[u]),1);
		seg3.modify(1,1,n,u);
	}
	pr2(ans);
	return 0;
}
