//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2676345#1
#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<cstdio>
#include<fstream>
#include<cstring>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define P pair<int,int>
#define ll __int64

int n,k;
int f,to,from,cost;
const int INF=222222222;

vector<P> G[1000];//first→終点 second→cost
int dist[1000];//頂点iへの最小距離

int keiro(int from,int to){
	for(int i=0;i<=n;i++)dist[i]=INF;
	//dist[from]=0;
	priority_queue<P,vector<P>,greater<P> >bfs;//first→頂点へのコスト second→頂点


	bfs.push(mp(0,from));


	while(!bfs.empty()){
		P now=bfs.top();
		bfs.pop();

		int index=now.second,ncost=now.first;


		if(dist[index]!=INF)continue;
		//cout<<index<<" "<<ncost<<endl;
		dist[index]=ncost;

		for(int i=0;i<G[index].size();i++){

			bfs.push(mp(ncost+G[index][i].second,G[index][i].first));
			//cout<<G[index][i].first<<" "<<G[index][i].second<<endl;
		}
	}

//rep(i,n+1)cout<<dist[i]<<" ";
	if(dist[to]==INF)return -1;
	return dist[to];
}
int main(){
while(cin>>n>>k,n||k){
for(int i=0;i<200;i++)G[i].clear();

for(int i=0;i<k;i++){
	cin>>f;
	if(!f){
		cin>>from>>to;
		cout<<keiro(from,to)<<endl;
	}
	else{
		cin>>from>>to>>cost;
		G[from].push_back(mp(to,cost));
		G[to].push_back(mp(from,cost));
	}
}
}
	return 0;
}
