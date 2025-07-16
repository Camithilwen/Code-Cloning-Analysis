#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;
using G = vector<map<int, int>>;

void
dfs(int node, ll count, G &arr, vector<bool> seen, vector<long> &to_K)
{
  seen[node] = true;
  for(auto child: arr[node]){
    if(seen[child.first]) continue;
    to_K[child.first] = count + child.second;
    dfs(child.first, count + child.second, arr, seen, to_K);
  }
}

int 
main() {
  int N; cin >> N;
  G arr(N + 1);
  rep(i, 0, N - 1){
    int a, b, c; cin >> a >> b >> c;
    arr[a][b] = c;
    arr[b][a] = c;
  }
  vector<long> to_K(N + 1);

  int Q, K; cin >> Q >> K;
  vector<pair<int, int>> q(Q);
  rep(i, 0, Q){
    cin >> q[i].first;
    cin >> q[i].second;
  }

  vector<bool> seen(N + 1, false);
  //dfs(K, 0, arr, seen, to_K);

  queue<int> que;
  que.push(K);
  seen[K] = true;
  to_K[K] = 0;
  while(!que.empty()){
    int node = que.front();
    que.pop();
    for(auto child : arr[node]){
      if(seen[child.first]) continue;
      to_K[child.first] = arr[node][child.first] + to_K[node];
      seen[child.first] = true;
      que.push(child.first);
    }
  }


  rep(i, 0, Q){
    cout << to_K[q[i].first] + to_K[q[i].second] << endl;
  }

}