/*Hatsune Miku 4ever!*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i,a,b) for(int i = (a);i < b;i ++)
#define _rep(i,a,b) for(int i = (a);i > b;i --)
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(x) ((x)&(-x))
#define pb push_back
#define MIKU 39
#define Design ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug() printf("Miku Check OK!\n")
#define maxn 200039

int n, m;
struct SegTree
{
	struct SegNode
	{
		int l,r; 
		ll add;
		ll ans;
		#define l(x) tree[x].l
		#define r(x) tree[x].r
		#define add(x) tree[x].add
		#define ANS(x) tree[x].ans
	}tree[maxn<<2];
	void build(int p,int l,int r)
	{
		add(p) = 0;
		l(p) = l,r(p) = r;
		if(l==r)
		{
			ANS(p) = 0;
			return ;
		}
		int mid = (l+r)/2;
		build(p*2, l, mid);
		build(p*2+1, mid+1, r);
	}

	void spread(int p)
	{
		if(add(p))
		{
			ANS(p*2) = l(p) - add(p);
			ANS(p*2+1) = (l(p)+r(p))/2+1-add(p); 
			add(p*2) = add(p);
			add(p*2+1) = add(p);
			add(p) = 0;
		} 
	}
	void change(int p,int l,int r,ll d)
	{
		if(l <= l(p) && r >= r(p))
		{
			ANS(p) = l(p) - d;
			add(p) = d;
			return ;
		} 
		spread(p);
		int mid = (l(p)+r(p))/2;
		if(l <= mid)
			change(p*2, l, r, d);
		if(r > mid)
			change(p*2+1, l, r, d);
		ANS(p) = min(ANS(p*2),ANS(p*2+1));
	}
	ll ask(int p,int pos)
	{
		if(l(p)==r(p))
			return pos - ANS(p);
		spread(p);
		int mid = (l(p)+r(p))/2;
		if(pos <= mid)
			return ask(p*2, pos);
		else
			return ask(p*2+1, pos);
	}
}T;

int main()
{
	int H, W;
	scanf("%d%d",&H,&W);
	T.build(1,1,W);
	int now = 1;
	_for(i,1,H+1)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		if(now < a)
			T.change(1,a,b,T.ask(1,a-1));
		else if(now >= a && now <= b)
		{
			T.change(1,now,b,-1000000);
			now = b+1;
		}
		if(now > W)
			printf("-1\n");
		else
			printf("%lld\n",T.tree[1].ans+i);
	} 
	return 0;
}