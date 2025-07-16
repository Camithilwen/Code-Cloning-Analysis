#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,m,a[N],b[N];
struct SegT{
	ll l,r,val,pd,pd2;
}dp[8*N];
void build_tree(ll l,ll r,ll x)
{
	if(l>r)
	{
		return;
	}
	dp[x].l=l;
	dp[x].r=r;
	dp[x].val=0;
	dp[x].pd=0;
	dp[x].pd2=-1;
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1,a=x<<1;
	build_tree(l,mid,a);
	build_tree(mid+1,r,a|1);
	return;
}
void push_down(ll x)
{
	ll a=x<<1;
	dp[a].val+=dp[x].pd;
	dp[a|1].val+=dp[x].pd;
	dp[a].pd+=dp[x].pd;
	dp[a|1].pd+=dp[x].pd;
	dp[x].pd=0;
	return;
}
void push_down2(ll x)
{
	ll a=x<<1;
	dp[a].val=dp[x].val;
	dp[a|1].val=dp[a|1].l-dp[a].l+dp[x].val;
	dp[a].pd2=dp[x].pd2;
	dp[a|1].pd2=dp[x].pd2;
	dp[a].pd=0;
	dp[a|1].pd=0;
	dp[x].pd=0;
	dp[x].pd2=-1;
	return;
}
void update(ll l,ll r,ll x)
{
	if(l>r)
	{
		return;
	}
	ll tl=dp[x].l,tr=dp[x].r;
	if(tl>r||tr<l)
	{
		return;
	}
	if(dp[x].pd2!=-1)
	{
		push_down2(x);
	}
	push_down(x);
	if(l<=tl&&tr<=r)
	{
		dp[x].val++;
		dp[x].pd++;
		return;
	}
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(l,r,a);
	}
	if(mid<r)
	{
		update(l,r,a|1);
	}
	dp[x].val=min(dp[a].val,dp[a|1].val);
	return;
}
ll query(ll l,ll r,ll x)
{
	if(l<0||r<0||l>=m||r>=m)
	{
		return LINF;
	}
	ll tl=dp[x].l,tr=dp[x].r;
	if(tl>r||tr<l)
	{
		return LINF;
	}
	if(dp[x].pd2!=-1)
	{
		push_down2(x);
	}
	push_down(x);
	if(l<=tl&&tr<=r)
	{
		return dp[x].val;
	}
	ll mid=(tl+tr)>>1,a=x<<1,ret=LINF;
	if(mid>=l)
	{
		ret=min(ret,query(l,r,a));
	}
	if(mid<r)
	{
		ret=min(ret,query(l,r,a|1));
	}
	dp[x].val=min(dp[a].val,dp[a|1].val);
	return ret;
}
void update2(ll l,ll r,ll x,ll val)
{
	if(l>r)
	{
		return;
	}
	ll tl=dp[x].l,tr=dp[x].r;
	if(l<=tl&&tr<=r)
	{
		dp[x].val=val+tl-l+1;
		dp[x].pd=0;
		dp[x].pd2=l;
		dp[x<<1].pd=0;
		dp[(x<<1)|1].pd=0;
		push_down2(x);
		return;
	}
	if(dp[x].pd2!=-1)
	{
		push_down2(x);
	}
	push_down(x);
	ll mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update2(l,r,a,val);
	}
	if(mid<r)
	{
		update2(l,r,a|1,val);
	}
	dp[x].val=min(dp[a].val,dp[a|1].val);
	return;
}
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		a[i]--;
		b[i]--;
	}
	build_tree(0,m-1,1);
	for(i=1;i<=n;i++)
	{
		update(0,a[i-1]-1,1);
		update(b[i-1]+1,m-1,1);
		update2(a[i-1],b[i-1],1,query(a[i-1]-1,a[i-1]-1,1));
//		for(j=0;j<m;j++)
//		{
//			query(j,j,1);
//		}
		j=dp[1].val;
		if(j<INF)
		{
			printf("%lld\n",j);
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}