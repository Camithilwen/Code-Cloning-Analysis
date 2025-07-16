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
vector<int>g[maxn],vis(maxn),clr(maxn);
int cnt[2]={0,0};
int n,m,biparite=1;
void dfs(int u,int c){
	vis[u]=1;
	clr[u]=c;
	cnt[clr[u]]++;
	for(auto v:g[u]){
		if( !vis[v]){
			dfs(v,c^1);
		}else if( clr[v] == c){
			biparite=0;
		}
	}
}
			
int32_t main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	if( ! biparite ){
		cout << ( n * ( n - 1 ) / 2 - m ) << endl;
	}else{
		cout << cnt[0] * cnt[1] - m << endl;
	}
}
/*
 * long long or int?
 * index out of bound?
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
