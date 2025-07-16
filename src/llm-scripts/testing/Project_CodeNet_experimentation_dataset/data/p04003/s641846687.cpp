#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002

int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<map<int,vector<int>>> E(N);
	
	for(int i=0;i<M;i++){
		int p,q,c;
		scanf("%d %d %d",&p,&q,&c);
		p--;q--;
		E[p][c].push_back(q);
		E[q][c].push_back(p);
	}
	
	map<pair<int,int>,int> dis;
	dis[make_pair(0,0)]=0;
	deque<pair<int,int>> Q;
	Q.push_back(make_pair(0,0));
	set<pair<int,int>> visited;
	while(Q.size()!=0){
		int x = Q.back().first;
		int u = Q.back().second;
		Q.pop_back();
		if(visited.count(make_pair(x,u)))continue;
		if(x==0){
			for(auto a:E[u]){
				int v = a.first;
				if(dis.count(make_pair(v,u)))continue;
				dis[make_pair(v,u)] = dis[make_pair(x,u)]+1;
				Q.emplace_front(v,u);
			}
		}
		else{
			for(int i=0;i<E[u][x].size();i++){
				int v = E[u][x][i];
				if(dis.count(make_pair(x,v))&&dis[make_pair(x,v)]<=dis[make_pair(x,u)])continue;
				dis[make_pair(x,v)]=dis[make_pair(x,u)];
				Q.emplace_back(x,v);
			}
			int v = u;
			if(dis.count(make_pair(0,v))&&dis[make_pair(0,v)]<=dis[make_pair(x,u)])continue;
			dis[make_pair(0,v)]=dis[make_pair(x,u)];
			Q.emplace_back(0,v);
		}
	}
	
	pair<int,int> ans(0,N-1);
	if(dis.count(ans))cout<<dis[ans]<<endl;
	else cout<<-1<<endl;
	
	return 0;
}