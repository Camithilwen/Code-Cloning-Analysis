#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,n2=1,q,a[500010],lst[500010],dat[2000010],ans[500010];
vector <pii> v[500010];

void upd(int k,int val)
{
	dat[k]+=val;
	while(k>0)
	{
		k=(k-1)/2;
		dat[k]+=val;
	}
}

int query(int k,int lb,int ub,int tlb,int tub)
{
	if(ub<tlb||tub<lb) return 0;
	if(tlb<=lb&&ub<=tub) return dat[k];
	return query(k*2+1,lb,(lb+ub)/2,tlb,tub)+query(k*2+2,(lb+ub)/2+1,ub,tlb,tub);
}

int main()
{
	cin>>n>>q;
	rep(i,n) scanf("%d",&a[i]);
	int x,y;
	rep(i,q)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		v[y].pb(mpr(x,i));
	}
	rep(i,n+5) lst[i]=-1;
	while(n2<n) n2*=2;
	rep(i,n)
	{
		if(lst[a[i]]>-1) upd(lst[a[i]]+n2-1,-1);
		upd(i+n2-1,1);
		lst[a[i]]=i;
		rep(j,v[i].size()) ans[v[i][j].se]=query(0,0,n2-1,v[i][j].fi,i);
	}
	rep(i,q) printf("%d\n",ans[i]);
	return 0;
}