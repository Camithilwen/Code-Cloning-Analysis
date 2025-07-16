#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cost[101][101];
int d[101];
bool used[101]={};
int n,k;
#define INF 10000000
int V;
void dijkstra(int s){
	fill(d,d+101,INF);
	fill(used,used+101,false);
	d[s]=0;
	while(1){
		int c=-1;
		for(int u=0;u<V;u++){
			if(!used[u] && (c==-1 || d[u]<d[c])){
				c=u;
			}
		}
		if(c==-1){
			break;
		}
		used[c]=true;
		for(int i=0;i<V;i++){
			d[i]=min(d[i],d[c]+cost[c][i]);
		}
	}
}
int main(){
	while(1){
	scanf("%d %d",&n,&k);
	if(!(n+k)) break;
	for(int i=0;i<101;i++){
		for(int j=0;j<101;j++){
			cost[i][j]=INF;
		}
	}
	V=n;
	for(int i=0;i<k;i++){
		int q;
		scanf("%d",&q);
		if(q){
			int r,o,p;
			scanf("%d %d %d",&r,&o,&p);
			cost[r-1][o-1]=min(p,cost[r-1][o-1]);
			cost[o-1][r-1]=min(p,cost[o-1][r-1]);
		}else{
			int r,p;
			scanf("%d %d",&r,&p);
			dijkstra(r-1);
			if(d[p-1]==INF){
				printf("%d\n",-1);
			}else{
				printf("%d\n",d[p-1]);
			}
		}
	}
	}
	return 0;
}