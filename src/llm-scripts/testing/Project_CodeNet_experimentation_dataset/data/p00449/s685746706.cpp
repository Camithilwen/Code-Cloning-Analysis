#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
typedef pair<int,int> pii;
#define MAX_V 110
#define INF (1<<30)

struct edge{int to,cost;};
vector<edge> G[MAX_V],IN[MAX_V];
int d[MAX_V];
 
void dijkstra(int s,int V){
    priority_queue< pii,vector<pii>,greater<pii> > que;
    rep(i,V)d[i]=INF;
    d[s]=0;
    que.push(pii(0,s));
     
    while(que.size()){
        pii p=que.top();
        que.pop();
         
        int v=p.second;
        if(d[v]<p.first)continue;
         
        rep(i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(pii(d[e.to],e.to));
            }
        }
    }
}

int N,M,o;
int maze[100][100],tim[100][100];
int main(void){
	while(cin>>N>>M,N+M){
		rep(i,MAX_V)G[i].clear();
		while(M--){
			cin>>o;
			if(o){
				int a,b,c;
				cin>>a>>b>>c;
				--a,--b;
				edge e = {b,c}, e1 = {a,c};
				G[a].push_back(e);
				G[b].push_back(e1);
			}else{
				int a,b;
				cin>>a>>b;
				--a,--b;
				dijkstra(a,N);
				cout<<(d[b]==(1<<30)?-1:d[b])<<endl;
			}
		}
	}
	

}