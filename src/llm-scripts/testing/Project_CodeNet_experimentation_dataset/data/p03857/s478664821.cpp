#include<bits/stdc++.h>
#define LL long long
#define MAXN 200005
using namespace std;

int N,M0,M1;
vector<int> adj[2][MAXN];
vector<int> s[2][MAXN];

int p[2][MAXN];
void dfs(int u, int x, int f){
	p[f][u] = x;
	s[f][x].push_back(u);
	
	int v;
	for(int k=0;k<adj[f][u].size();k++){
		v = adj[f][u][k];
		if(!p[f][v]) dfs(v, x, f);
	}
}

int ans[MAXN], vis[MAXN];
void work(int id){
	int x = p[0][id];
	int v;
	for(int k=0;k<s[0][x].size();k++){
		v = s[0][x][k];
		vis[p[1][v]]++;
	}

	for(int k=0;k<s[0][x].size();k++){
		v = s[0][x][k];
		ans[v] = vis[p[1][v]];
	}
	
	for(int k=0;k<s[0][x].size();k++){
		v = s[0][x][k];
		vis[p[1][v]]--;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>N>>M0>>M1;
	
	int u,v;
	for(int i=1;i<=M0;i++){
		cin>>u>>v;
		adj[0][u].push_back(v);
		adj[0][v].push_back(u);
	}
	for(int i=1;i<=M1;i++){
		cin>>u>>v;
		adj[1][u].push_back(v);
		adj[1][v].push_back(u);
	}
	
	for(int i=1;i<=N;i++){
		if(!p[0][i]){
			dfs(i,i,0);
		}
		if(!p[1][i]){
			dfs(i,i,1);
		}
	}
	
	for(int i=1;i<=N;i++){
		if(ans[i] == 0){
			work(i);
		}
	}
	
	//for(int i=1;i<=N;i++) cout<<p1[i]<<" "<<p2[i]<<endl;
	for(int i=1;i<=N;i++) cout<<ans[i]<<" ";
	return 0;
}

