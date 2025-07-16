#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 100010
vector<ll> g[N];
ll col[N];
ll cnt;
bool nibu;
void dfs(ll x,ll c){
	if(~col[x]){
		if(c!=col[x])nibu=0;
		return;
	}
	cnt++;
	col[x]=c;
	for(auto y:g[x])dfs(y,c^1);
}
ll n,m;
int main(){
	cin>>n>>m;
	rep(i,m){
		ll a,b; cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rep(i,n)col[i]=-1;
	ll nonone=0;
	ll sei=0,nisei=0;
	rep(i,n)if(col[i]==-1){
		cnt=0;
		nibu=1;
		dfs(i,0);
		if(cnt>1){
			nonone+=cnt;
			sei++;
			if(nibu)nisei++;
		}
	}
	ll ans=n*n-nonone*nonone;
	ans+=sei*sei+nisei*nisei;
	cout<<ans<<endl;
}



