#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
int n,q,a,b; 
ll x[222222];

struct node
{
	ll lazy;
	ll ans;
};

node st[2][800111];

void build(int ty, int id, int l, int r)
{
	st[ty][id].lazy=0;
	if(r-l<2)
	{
		st[ty][id].ans=ll(1e14);
		if(l==a)
		{
			st[ty][id].ans=abs(x[0] - b);
		}
		if(ty==0) st[ty][id].ans-=l;
		else st[ty][id].ans+=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(ty,id*2,l,mid); build(ty,id*2+1,mid,r);
	st[ty][id].ans=min(st[ty][id*2].ans,st[ty][id*2+1].ans);
}

void push(int ty, int id, int l, int r)
{
	if(st[ty][id].lazy!=0)
	{
		st[ty][id].ans+=st[ty][id].lazy;
		if(r-l>=2)
		{
			st[ty][id*2].lazy+=st[ty][id].lazy;
			st[ty][id*2+1].lazy+=st[ty][id].lazy;
		}
		st[ty][id].lazy=0;
	}
}

void update(int ty, int id, int l, int r, int pos, ll v)
{
	push(ty,id,l,r);
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[ty][id].ans=min(v,st[ty][id].ans);
		return ;
	}
	int mid=(l+r)>>1;
	update(ty,id*2,l,mid,pos,v); update(ty,id*2+1,mid,r,pos,v);
	st[ty][id].ans=min(st[ty][id*2].ans,st[ty][id*2+1].ans);
}

void add(int ty, int id, int l, int r, int ql, int qr, ll v)
{
	push(ty,id,l,r);
	if(ql>=r||l>=qr) return ;
	if(ql<=l&&r<=qr)
	{
		st[ty][id].lazy+=v;
		push(ty,id,l,r);
		return ;
	}
	int mid=(l+r)>>1;
	add(ty,id*2,l,mid,ql,qr,v); add(ty,id*2+1,mid,r,ql,qr,v);
	st[ty][id].ans=min(st[ty][id*2].ans,st[ty][id*2+1].ans);
}

ll query(int ty, int id, int l, int r, int ql, int qr)
{
	push(ty,id,l,r);
	if(ql>=r||l>=qr) return ll(1e15);
	if(ql<=l&&r<=qr) return st[ty][id].ans;
	int mid=(l+r)>>1;
	return min(query(ty,id*2,l,mid,ql,qr), query(ty,id*2+1,mid,r,ql,qr));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q>>a>>b; a--; b--;
	for(int i=0;i<q;i++) {cin>>x[i]; x[i]--;}
	ll ans=ll(1e18);
	for(int z=0;z<2;z++)
	{
		for(int ty=0;ty<2;ty++) build(ty,1,0,n);
		for(int i=1;i<q;i++)
		{
			ll real = min(query(0,1,0,n,0,x[i]) + x[i], query(1,1,0,n,x[i],n) - x[i]);
			for(int j=0;j<2;j++) add(j,1,0,n,0,n,abs(x[i-1]-x[i]));
			update(0,1,0,n,x[i-1],real-x[i-1]);
			update(1,1,0,n,x[i-1],real+x[i-1]);
		}
		for(int i=0;i<n;i++)
		{
			ans=min(ans,query(0,1,0,n,i,i+1)+i);
		}
		swap(a,b);
	}
	cout<<ans<<'\n';
}
