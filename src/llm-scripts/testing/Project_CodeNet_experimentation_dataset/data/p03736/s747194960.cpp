#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define int ll
#define get getchar()
#define in inline
in int read()
{
	int t=0; char ch=get;
	while(ch<'0' || ch>'9') ch=get;
	while(ch<='9' && ch>='0') t=t*10+ch-'0', ch=get;
	return t;
}
const int _=2e5+5;
int n,q,A,B,x[_];
ll lazy[_<<4],min1[_<<4],min2[_<<4];
in void pushdown(int k)
{
	if(lazy[k]==0) return ;
	int x=lazy[k];
	lazy[k]=0;
	lazy[k<<1]+=x;
	lazy[k<<1|1]+=x;
	min1[k<<1]+=x;
	min1[k<<1|1]+=x;
	min2[k<<1]+=x;
	min2[k<<1|1]+=x;
}
in void update(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		min1[k]=min(min1[k],(ll)(y-l));
		min2[k]=min(min2[k],(ll)(y+l));
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(x<=mid) update(k<<1,l,mid,x,y);
	else update(k<<1|1,mid+1,r,x,y);
	min1[k]=min(min1[k<<1],min1[k<<1|1]);
	min2[k]=min(min2[k<<1],min2[k<<1|1]);
}
/*#define ls(_o) (_o << 1)
#define rs(_o) ((_o << 1) | 1)
ll query1(int rl, int rr, int l, int r, int tree) {
        if (rl == l && rr == r)
            return (min1[tree]);
        int mid = (l + r) >> 1;
        pushdown(tree);
        if (rl > mid)
            return (query1(rl, rr, mid + 1, r, rs(tree)));
        if (rr <= mid)
            return (query1(rl, rr, l, mid, ls(tree)));
        return (min(query1(rl, mid, l, mid, ls(tree)), query1(mid + 1, rr, mid + 1, r, rs(tree))));
    }
ll query2(int rl, int rr, int l, int r, int tree) {
        if (rl == l && rr == r)
            return (min2[tree]);
        int mid = (l + r) >> 1;
        pushdown(tree);
        if (rl > mid)
            return (query2(rl, rr, mid + 1, r, rs(tree)));
        if (rr <= mid)
            return (query2(rl, rr, l, mid, ls(tree)));
        return (min(query2(rl, mid, l, mid, ls(tree)), query2(mid + 1, rr, mid + 1, r, rs(tree))));
		}*/

  in int query1(int k,int l,int r,int x,int y)
{
//	cout<<1<<":: "<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	if(l==x && r==y) return min1[k];
	pushdown(k);
	int mid=l+r>>1,minn=0x3f3f3f3f;
	if(y<=mid) return query1(k<<1,l,mid,x,y);
	if(x>mid) return query1(k<<1|1,mid+1,r,x,y);
	return min(query1(k<<1,l,mid,x,mid),query1(k<<1|1,mid+1,r,mid+1,y));
	}
in int query2(int k,int l,int r,int x,int y)
{
//	cout<<2<<":: "<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	if(l==x && r==y) return min2[k];
	pushdown(k);
	int mid=l+r>>1,minn=0x3f3f3f3f;
	if(y<=mid) return query2(k<<1,l,mid,x,y);
	if(x>mid) return query2(k<<1|1,mid+1,r,x,y);
	return min(query2(k<<1,l,mid,x,mid),query2(k<<1|1,mid+1,r,mid+1,y));
	}
in int getans(int k,int l,int r)
{
	if(l==r) return min1[k]+l;
	pushdown(k);
	int mid=l+r>>1;
	return min(getans(k<<1,l,mid), getans(k<<1|1,mid+1,r));
}
signed main()
{
	n=read(),q=read(),A=read(),B=read();
	x[0]=A;
	memset(min1,0x3f,sizeof(min1));
	memset(min2,0x3f,sizeof(min2));
	update(1,1,n,B,0);
	for(re int i=1;i<=q;i++)
	{
		x[i]=read();
		//int qwe=min(query1(1, x[i], 1, n, 1) + x[i], query2(x[i], n, 1, n, 1) - x[i]);
		int qwe=min(query1(1,1,n,1,x[i])+x[i],query2(1,1,n,x[i],n)-x[i]);
		lazy[1]+=abs(x[i]-x[i-1]);
		min1[1]+=abs(x[i]-x[i-1]);
		min2[1]+=abs(x[i]-x[i-1]);
		update(1,1,n,x[i-1],qwe);
	}
	cout<<getans(1,1,n);
}
