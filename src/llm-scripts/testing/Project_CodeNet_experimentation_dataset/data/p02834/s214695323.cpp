#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N, u, v; cin >> N >> u >> v;
  u--; v--;

  vector<vector<int>> e(N);
  for(int i = 0; i < N-1; i++){
    int x,y; cin >> x >> y;
    x--; y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  vector<int> a(N,-1);
  vector<int> t(N,-1);
  t[u] = 0;
  a[v] = 0;

  queue<int> qt,qa;

  qt.push(u);
  while(!qt.empty()){
    int now = qt.front();
    qt.pop();
    for(int next: e[now]){
      if(t[next] == -1){
        t[next] = t[now] + 1;
        qt.push(next);
      }
    }
  }

  int dist = t[v];

  qa.push(v);
  while(!qa.empty()){
    int now = qa.front();
    qa.pop();
    for(int next: e[now]){
      if(a[next] == -1){
        a[next] = a[now] + 1;
        qa.push(next);
      }
    }
  }
  t[u] = 2;

  int ans = 0;
  for(int i = 0; i < N; i++){
    if(a[i] >= t[i]){
      ans = max(ans, a[i]);
    }
  }
  cout << max(ans-1,0) << endl;
  // cerr << "dist: " << dist;

}
