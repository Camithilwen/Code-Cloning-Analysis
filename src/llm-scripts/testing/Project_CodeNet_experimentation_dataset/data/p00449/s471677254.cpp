#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct edge{
  int to,cost;
  edge(){}
  edge(int to,int cost):to(to),cost(cost){}
};
typedef pair<int,int> P;

int d[101];
const int INF=(int)1e9;

int main(void){
  int n,k;
  while(cin>>n>>k,!(n==0&&k==0)){
    vector<edge> G[1000];
    for(int i=0;i<k;i++){
      int r,a,b,cost;
      cin>>r;
      if(r==1){
	cin>>a>>b>>cost;
	G[a].push_back(edge(b,cost));
	G[b].push_back(edge(a,cost));
      }
      if(r==0){
	cin>>a>>b;
	priority_queue<P,vector<P>,greater<P> > que;
	fill(d,d+101,INF);
	d[a]=0;
	que.push(P(0,a));
	while(!que.empty()){
	  P p=que.top();
	  que.pop();
	  if(d[p.second]<p.first)continue;
	  for(int j=0;j<G[p.second].size();j++){
	    edge e=G[p.second][j];
	    if(d[e.to]>d[p.second]+e.cost){
	      d[e.to]=d[p.second]+e.cost;
	      que.push(P(d[e.to],e.to));
	    }
	  }
	}
	if(d[b]==(int)INF){
	  cout<<"-1"<<endl;
	}else{
	  cout<<d[b]<<endl;
	}
      }
    }
  }
  return 0;
}