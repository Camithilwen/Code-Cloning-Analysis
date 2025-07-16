#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct Edge{
  ll to;
  ll weight;
  Edge(ll t,ll w) : to(t),weight(w){}
};

using Graph = vector<vector<Edge>>;



int main(){
  int n;
  cin >> n;
  Graph G(n);

  for(int i=0;i<n-1;++i){
    ll from,to,weight;
    cin >> from >> to >> weight;
    from--;
    to--;
    G[from].push_back(Edge(to,weight));
    G[to].push_back(Edge(from,weight));
  }
  vector<ll> dist(n,-1);
  queue<ll> que;
  int q,k;
  cin >> q >> k;
  k--;
  //cout << q << endl;
  vector<ll> x(q),y(q);
  for(int i=0;i<q;i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    //cout << "OK" << endl;
  }
  dist[k]=0;
  que.push(k);
  while(!que.empty()){
    ll v=que.front();
    que.pop();
    for(auto nv : G[v]){
      if(dist[nv.to]==-1 || dist[nv.to]>dist[v]+nv.weight){
        dist[nv.to]=dist[v]+nv.weight;
        que.push(nv.to);
      }
    }
  }
  for(int i=0;i<q;++i){
    ll ans=dist[x[i]]+dist[y[i]];
    cout << ans << endl;
  }
  return 0;
}
