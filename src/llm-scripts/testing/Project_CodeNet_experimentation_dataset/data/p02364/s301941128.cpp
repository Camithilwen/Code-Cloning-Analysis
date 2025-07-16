#include<bits/stdc++.h>
using namespace std;

struct Edge{
  int to,cost;
  bool operator<(const Edge&a)const{
    return cost>a.cost;
  }
};
struct Graph{
  Graph(int n):E(n),T(n),N(n){}
  vector<vector<Edge>>E,T;
  int N;
  void add_edge(int a,int b,int c){
    E[a].push_back({b,c});
    E[b].push_back({a,c});
  }
  void prim(int s){
    bool visited[N];
    priority_queue<pair<Edge,int>>Q;
    memset(visited,0,N);
    Q.push({{s,0},-1});
    while(Q.size()){
      Edge e=Q.top().first;
      int from=Q.top().second;Q.pop();
      if(visited[e.to])continue;
      visited[e.to]=1;
      if(from+1)T[from].push_back(e),T[e.to].push_back({from,e.cost});
      for(auto&a:E[e.to])
      if(!visited[a.to])Q.push({a,e.to});
    }
  }
  int get_cost(){
    int ret=0;
    for(auto&a:T)for(auto&b:a)ret+=b.cost;
    return ret/2;
  }
  vector<Edge>* get_MST(){
    return T.data();
  }
};

main(){
  int V,E,a,b,c;
  cin>>V>>E;
  Graph G(V);
  for(int i=0;i++<E;G.add_edge(a,b,c))cin>>a>>b>>c;
  G.prim(0);
  cout<<G.get_cost()<<endl;
}