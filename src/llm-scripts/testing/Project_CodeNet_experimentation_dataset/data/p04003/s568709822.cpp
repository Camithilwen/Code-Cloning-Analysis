#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("Ofast")
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define siz(s) (int)s.size()

template<class T> inline bool chmin(T &a, T b) {
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b) {
	if(a<b){a=b;return true;}
	return false;
}
template<class T> inline int getidx(vector<T> &v, T a) {
	return lower_bound(all(v), a) - v.begin();
}

constexpr int mod=1e9+7;
constexpr int inf=3e18;


int N,M;
vector<int>G[100005];
vector<int>G2[300005];
bool used[100005];
vector<int>xx;
void dfs(int x){
	used[x]=true;
	for(int i:G[x])if(!used[i]){
		dfs(i);
	}
	xx.push_back(x);
}
int bfs(){
	queue<P>que;
	int dis[300005];
	fill(dis,dis+300000,inf);
	dis[0]=0;que.push({0,0});
	while(!que.empty()){
		P p=que.front();que.pop();
		if(dis[p.second]<p.first)continue;
		for(int i:G2[p.second]){
			if(dis[i]==inf){
				dis[i]=p.first+1;
				que.push({dis[i],i});
			}
		}
	}
	return dis[N-1];
}
vector<P>edge[1000005];
signed main(){
	cin>>N>>M;
	rep(i,M){
		int a,b,c;cin>>a>>b>>c;a--;b--;c--;
		edge[c].push_back({a,b});
	}
	int now=100000;
	rep(i,1000000){
		for(P j:edge[i]){
			G[j.first].push_back(j.second);
			G[j.second].push_back(j.first);
		}
		for(P j:edge[i]){
			if(!used[j.first]){
				dfs(j.first);
				for(int k:xx){
					G2[now].push_back(k);
					G2[k].push_back(now);
				}
				now++;
				xx.clear();
			}
			if(!used[j.second]){
				dfs(j.second);
				for(int k:xx){
					G2[now].push_back(k);
					G2[k].push_back(now);
				}
				now++;
				xx.clear();
			}
		}
		for(P j:edge[i]){
			used[j.first]=false;
			used[j.second]=false;
			G[j.first].clear();
			G[j.second].clear();
		}
	}
	int ans=bfs();
	cout<<(ans==inf?-1:ans/2)<<endl;
}
