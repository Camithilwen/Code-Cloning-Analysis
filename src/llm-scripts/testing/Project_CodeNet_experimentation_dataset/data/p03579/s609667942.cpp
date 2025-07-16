#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(){
  long long int n, m;
  cin >> n >> m;
  vector<int> d(n, 0);
  vector<vector<int>> E(n);
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    a--;b--;
    E[a].emplace_back(b);
    E[b].emplace_back(a);
  }
  vector<bool> visited(n, false);
  function<void(int)> dfs = [&](int cur){
    visited[cur] = true;
    for(auto&& to:E[cur]){
       if (!visited[to]){
         d[to] = d[cur] + 1;
         dfs(to);
       }
    }
  };
  dfs(0);
  bool is_digraph = true;
  for(int i=0;i<n;i++){
    for(auto&& t:E[i]){
      if(!((d[i]^d[t])&1)){
        is_digraph = false; 
      }
    }
  }
  // cerr << is_digraph << endl;
  // for(auto&& r:d)cerr << r << " ";
  // cerr << endl;
  if(is_digraph){
    long long int even = 0;
    for(auto&& r:d)even += (r % 2 == 0);
    cout << even * (n - even) - m << endl;
  }else{
    cout << n * (n - 1) / 2 - m << endl; 
  }
}
