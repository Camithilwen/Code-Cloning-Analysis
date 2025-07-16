#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

template<class T>struct dijkstra{//T=int or ll
  struct Node{
    vector<T> edges_to;
    vector<T> edges_cost;
    bool done;
    T cost=-1;
  };
  vector<Node> graph;
  void init(T N){
    graph.resize(N);
  }
  void add(T from, T to, T cost){
    graph[from].edges_to.push_back(to);
    graph[from].edges_cost.push_back(cost);
  }
  void shortest(T start){
    priority_queue<pair<T,T>,vector<pair<T,T>>,greater<pair<T,T>>> d;
    d.push(make_pair(0,start));
    while(!d.empty()){
      pair<T,T> p = d.top();
      d.pop();
      Node &point = graph[p.second];
      if(point.done) continue;
      point.done = true;
      point.cost = p.first;
      for(T i = 0; i < (T)point.edges_to.size(); i++){
        if(graph[point.edges_to[i]].done)continue;
        d.push(make_pair(point.cost+point.edges_cost[i],point.edges_to[i]));
      }
    }
  }
};

int main() {
  ll N;
  cin>>N;
  dijkstra<ll> D;
  D.init(N);
  for(ll i = 0; i < N-1; i++) {
    ll x,y,z;
    cin>>x>>y>>z;
    D.add(x-1,y-1,z);
    D.add(y-1,x-1,z);
  }
  ll Q,K;
  cin>>Q>>K;
  D.shortest(K-1);
  for(ll i = 0; i < Q; i++){
    ll x,y;
    cin>>x>>y;
    cout<<D.graph[x-1].cost+D.graph[y-1].cost<<endl;
  }
}