#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin>>n;
	vector<vector<pair<ll,ll>>>ro(n+1);
	for(int i=0;i<n-1;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		ro[a].push_back({b,c});
		ro[b].push_back({a,c});
	}
	queue<ll>que;
	ll q,k;
	cin>>q>>k;
	ll dis[114514];
	for(int i=1;i<=n;i++)dis[i]=-1;
	que.push(k);
	dis[k]=0;
	while(!que.empty()){
		ll x=que.front();
		que.pop();
		for(int i=0;i<ro[x].size();i++){
			if(dis[ro[x][i].first]!=-1)continue;
			dis[ro[x][i].first]=dis[x]+ro[x][i].second;
			que.push(ro[x][i].first);
		}
	}
	for(int i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		cout<<dis[a]+dis[b]<<endl;
	}
	return 0;
}
