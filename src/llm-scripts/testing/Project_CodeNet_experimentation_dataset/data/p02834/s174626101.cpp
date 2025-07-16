#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;
// typedef long long int 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
// typedef pair<ll,ll> pll;
const int modi = 1e9+7;
const int mxn = 1e5+10;
vi adj[mxn];

void dfs(int u ,int p, int* dis, int d = 0){
	dis[u] = d;
	for(auto v:adj[u]){
		if(v==p)continue;

		dfs(v,u,dis,d+1);
	}
}

void solve(){
	int n;
	cin >> n;
	int t,a; // t is going away a is coming near
	cin >> t >> a;
	--t,--a;
	for(int i =0;i<n-1;i++){
		int u ,v;
		cin >> u >> v;
		--u,--v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int> leaves;
	for(int i =0;i<n;i++)
	{
		if(adj[i].size()==1){
			leaves.pb(i);
		}
	}

	int dt[n],da[n];
	dfs(t,-1,dt);
	dfs(a,-1,da);
	int ans =0;
	for(auto e:leaves){
		// cout << e << " " << endl;
		if(dt[e]>da[e])
			continue;
		ans = max(ans,da[e]-1);
	}
	cout << ans << endl;
 }
int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	// int t;cin >> t;while(t--)
		solve();
}
