#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct Graph{
  Graph(int n):E(n),d(n){}
  vector<vector<tuple<int,int,int>>>E;
  vector<int>d;
  void add_edge(int a,int b,int c,int d){
    E[a].push_back(make_tuple(b,c,d));
  }
  void dijkstra(int s,int f){
    priority_queue<P,vector<P>,greater<P>>q;
    fill(d.begin(),d.end(),1e9);
    q.push({d[s]=0,s});
    while(q.size()){
      auto p=q.top();q.pop();
      if(p.first>d[p.second])continue;
      for(auto& a:E[p.second]){
        int x=get<0>(a),y=get<1>(a)+p.first;
        if(f)y=get<2>(a)+p.first;
        if(y<d[x])d[x]=y,q.push({y,x});
      }
    }
  }
};
main(){
  int n,m,a,b,c,d,k;
  while(cin>>n>>m,n){
    Graph E(m);
    for(int i=0;i++<n;E.add_edge(--a,--b,c,d),E.add_edge(b,a,c,d))cin>>a>>b>>c>>d;
    cin>>k;
    for(int i=0;i++<k;cout<<E.d[--b]<<endl){
      cin>>a>>b>>c;
      E.dijkstra(--a,c);
    }
  }
}