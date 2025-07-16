#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int K, ans;

int par [MAX_N];
vector<int> adj [MAX_N];

int subh [MAX_N];
int del [MAX_N];

void dfs (int u) {
  subh[u] = 0;
  for (int nxt : adj[u]) {
    dfs(nxt);
    if (!del[nxt]) {
      subh[u] = max(subh[u], 1 + subh[nxt]);
    }
  }

  if (u != 1 && subh[u] == K - 1 && par[u] != 1) {
    del[u] = 1;
    ans++;
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> K;

  for (int i = 1; i <= n; i++) {
    cin >> par[i];
  }

  if (par[1] != 1) ans++;
  for (int i = 2; i <= n; i++) {
    adj[par[i]].push_back(i);
  }

  dfs(1);

  cout << ans << endl;
}
