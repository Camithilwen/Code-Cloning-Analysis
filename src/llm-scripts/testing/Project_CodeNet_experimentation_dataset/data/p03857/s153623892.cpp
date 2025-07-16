#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() int t;cin>>t;for(int test=1;test<=t;test++)
#define pb push_back
#define nl cout<<"\n"
#define F first
#define S second
#define all(x) x.begin(),x.end()

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }

const ll MOD = 1000000007;
ll mod( ll n, ll m=MOD ){ n%=m,n+=m,n%=m;return n; }

const int MAXN = 2e5+5;
const int LOGN = 21;
const ll INF = 1e14;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

template<class T1, class T2, class T3> void add( T1 &x, T2 y, T3 m = MOD )
{
	x += y;
	if( x >= m )
		x -= m;
}

template<class T1, class T2, class T3> void sub( T1 &x, T2 y, T3 m = MOD )
{
	x -= y;
	if( x < 0 )
		x += m;
}

vector<int>roads[MAXN], rails[MAXN];
vector<bool>vis(MAXN), vis2(MAXN);
int road_comp[MAXN], road_size[MAXN];
int rail_comp[MAXN], rail_size[MAXN], cc;

void roads_dfs( int node )
{
	vis[node] = 1;
	road_comp[node] = cc;
	road_size[cc]++;
	for( int next : roads[node] )
	{
		if( !vis[next] )
		{
			roads_dfs(next);
		}
	}
}

void rails_dfs( int node )
{
	vis2[node] = 1;
	rail_comp[node] = cc;
	rail_size[cc]++;
	for( int next : rails[node] )
	{
		if( !vis2[next] )
		{
			rails_dfs(next);
		}
	}
}

int main() 
{
	fastio();

	int n,k,l;
	cin>>n>>k>>l;
	for(int i=0;i<k;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		roads[u].pb(v);
		roads[v].pb(u);
	}
	for(int i=0;i<l;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		rails[u].pb(v);
		rails[v].pb(u);
	}

	cc = 0;
	for(int i=0;i<n;i++)
	{
		if( !vis[i] )
		{
			roads_dfs(i);
			cc++;
		}
	}

	cc = 0;
	for(int i=0;i<n;i++)
	{
		if( !vis2[i] )
		{
			rails_dfs(i);
			cc++;
		}
	}

	vector<int>order;
	for(int i=0;i<n;i++)
		order.pb(i);

	auto cmp = [&]( int i, int j ) -> bool
	{
		if( road_comp[i] != road_comp[j] )
			return road_comp[i] < road_comp[j];
		return rail_comp[i] < rail_comp[j];
	};

	sort(all(order), cmp);

	vector<int>ans(n);
	for(int i=0;i<n;)
	{
		int a = road_comp[order[i]], b = rail_comp[order[i]];
		int j = i;
		while( j < n && road_comp[order[j]] == a && rail_comp[order[j]] == b ) j++;
		for(int k=i;k<j;k++)
			ans[order[k]] = j-i;
		i = j;
	}

	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
