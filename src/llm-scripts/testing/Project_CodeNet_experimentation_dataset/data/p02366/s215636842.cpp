#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

#define MAX_V 100000

int V, E;
vector<int> G[MAX_V];
bool visited[MAX_V];
int prenum[MAX_V];
int parent[MAX_V];
int lowest[MAX_V];
int timer, root;

void add_edge(int from, int to) {
  G[from].push_back(to);
  G[to].push_back(from);
}

void dfs(int u, int prev) {
    prenum[u] = timer;
    lowest[u] = timer;
    timer++;

    visited[u] = true;

    for(int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if(!visited[v]) {
        parent[v] = u;
        dfs(v, u);
        lowest[u] = min(lowest[u], lowest[v]);
      } else if(v != prev) {
        lowest[u] = min(lowest[u], prenum[v]);
      }
    }

}

int main () {
  cin >> V >> E;
  for(int i = 0; i < E; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    add_edge(v1, v2);
  }

  for(int i = 0; i < V; i++) {
    visited[i] = false;
  }
  root = 0;
  timer = 1;
  dfs(root, -1);

  set<int> ans;
  // (1)
  int num = 0;
  for(int i = 0; i < V; i++) {
    if(i == root) continue;
    if(parent[i] == root) num++;
  }
  if(num >= 2) ans.insert(root);

  // (2)
  for(int i = 0; i < V; i++) {
    if(i == root || parent[i] == root) continue;
    else if(prenum[parent[i]] <= lowest[i])
      ans.insert(parent[i]);
    // cout << i << endl;
  }

  set<int>::iterator it = ans.begin();
  while(it != ans.end()) {
    cout << *it << endl;
    it++;
  }

}