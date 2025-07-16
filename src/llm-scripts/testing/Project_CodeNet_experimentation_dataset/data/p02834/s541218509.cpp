
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}

vector<ll> adj[100010];
ll dp1[100010],dp2[100010];

void dfs1(ll i,ll par)
{
	ll j;
	for(j=0;j<sz(adj[i]);j++)
	{
		ll x = adj[i][j];
		if(x==par)
			continue;
		dp1[x] = dp1[i]+1;
		dfs1(x,i);
	}
	return ;
}

void dfs2(ll i,ll par)
{
	ll j;
	for(j=0;j<sz(adj[i]);j++)
	{
		ll x = adj[i][j];
		if(x==par)
			continue;
		dp2[x] = dp2[i]+1;
		dfs2(x,i);
	}
	return ;
}

int main()
{
	fastio;
	ll i,j,n,a,b;
	cin>>n>>a>>b;
	for(i=0;i<n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dp1[a]=0;
	dfs1(a,0);
	dp2[b]=0;
	dfs2(b,0);
	ll ma=-1e9,mi=1e9;
	for(i=1;i<=n;i++)
	{
		if(dp1[i]==dp2[i])
			mi=min(mi,dp1[i]);
		if((dp2[i]>dp1[i])&&(dp2[i]>2))
		{
			// if((dp1[i]+dp2[i])%2)
			// 	ma=max(dp2[i]-1,ma);
			// else
			ma=max(ma,dp2[i]-1);
		}
		// cout<<dp1[i]<<" "<<dp2[i]<<endl;
		// cout<<ma<<endl;
	}
	if(mi!=1e9)
		ma=max(ma,mi);
	if(ma==-1e9)
		ma=0;
	cout<<ma<<endl;
    return 0;
}



