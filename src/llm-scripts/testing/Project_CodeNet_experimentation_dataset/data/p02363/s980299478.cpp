#include<bits/stdc++.h>
using namespace std;
#define inf 1e12+1
typedef long long int ll;
typedef pair<ll,ll> mypair;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){

	ll v,e;
	cin>>v>>e;
	vector<vector<mypair> > g(v);
	vector<vector<ll> > dp(v,vector<ll>(v,inf) );
	ll s,t,d;
	rep(i,e){
	       	cin>>s>>t>>d,g[s].push_back(mypair(t,d) );
		dp[s][t]  = d;
	}
	rep(i,v)dp[i][i]=0;
	rep(k,v)rep(i,v)rep(j,v)if(dp[i][k]!=inf&dp[k][j]!=inf)dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
	bool flag =false;
	rep(i,v)if(dp[i][i]!=0)flag = true;
	if(flag){
	cout<<"NEGATIVE CYCLE"<<endl;
	}else{
	rep(i,v){
	rep(j,v){
	if(dp[i][j]==inf)cout<<"INF";
	else cout<<dp[i][j];
	if(j==v-1){}
	else cout<<' ';
	}
	cout<<endl;
	}
	}
		
	

	return 0;
}




