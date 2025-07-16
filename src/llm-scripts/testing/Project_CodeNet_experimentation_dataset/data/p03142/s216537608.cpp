#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N, M;
vector<vector<int>> graph;
vector<int> deg, order;

void toporo(){
  queue<int> que;
  REP(i, N){
    if(deg[i] == 0){
      que.push(i);
    }
  }
  while(!que.empty()){
    int v = que.front(); que.pop();
    order.push_back(v);

    for(auto nv : graph[v]){
      --deg[nv];
      if(deg[nv] == 0) que.push(nv);
    }
  }
  reverse(order.begin(), order.end());
}

int main(){
  cin >> N >> M;
  deg.resize(N);
  graph.resize(N);
  vector<vector<int>> in(N);

  REP(i, N+M-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[b].push_back(a);
    deg[a]++;
  }
  toporo();
  vector<int> depth(N);
  REP(i, N){
    depth[order[i]] = i;
  }
  REP(i, N){
    int oya = 0, d = -1;
    for(auto v :graph[i]){
      if(d < depth[v]){
        d = depth[v];
        oya = v+1;
      }
    }
    cout << oya << endl;
  }
  return 0;
}
