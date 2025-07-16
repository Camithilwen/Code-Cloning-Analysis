#include<iostream>

#define INF 5000000

using namespace std;
const int V=120;
int map[V][V]={INF};
int dis[V];
bool used[V];

int dijkstra(int s,int e){
	fill(dis,dis+V,INF);
	fill(used,used+V,false);
	dis[s]=0;
	while(true){
		int v=-1;
		for(int u=0;u<V;u++){
			if(!used[u] && (v==-1 || dis[u]<dis[v]))v=u;
		}
		if(v==-1)break;
		used[v]=true;
		for(int u=0;u<V;u++){
			dis[u]=min(dis[v]+map[v][u],dis[u]);
		}
	}
	if(dis[e]!=INF)return dis[e];
	else return -1;
}

int main(){
	int N,K;
	while(cin>>N>>K && N && K){
		fill((int*)map,(int*)map+V*V,INF);
		for(int loop=0;loop<K;loop++){
			int check;
			cin>>check;
			if(check==0){
				int s,e;
				cin>>s>>e;
				cout<<dijkstra(s,e)<<endl;
			}
			else {
				int c,d,e;
				cin>>c>>d>>e;
				map[c][d]=map[d][c]=min(map[c][d],e);
			}
		}
	}
}