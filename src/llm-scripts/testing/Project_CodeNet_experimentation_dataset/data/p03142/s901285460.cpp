#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e5+10;
vector<int>g[maxn],vis(maxn),dis(maxn),par(maxn),tpl;
int n,m;
void dfs(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if( !vis[v]){
			dfs(v);
		}
	}
	tpl.push_back(u);
}	
int32_t main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=n-1+m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if( !vis[i] ){
			dfs(i);
		}
	}
	reverse(tpl.begin(),tpl.end());
	for(int i=0;i<n;i++){
		int u = tpl[i];
		for(auto v:g[u]){
			if( dis[v] < dis[u] + 1){
				dis[v] = dis[u] + 1;
				par[v] = u;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout << par[i] << endl;
	}
}
/*
 * long long or int?
 * index out of bound?
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
