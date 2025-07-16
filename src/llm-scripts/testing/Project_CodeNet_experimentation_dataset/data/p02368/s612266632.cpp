#include <string.h>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>

using namespace std;

const int MAXV = 10010;

struct Edge {
  int u;
  int v;

  Edge(int u, int v): u(u), v(v) {}
};

int v, e, source = 0, dfs_clock = 0, scc_count = 0;
vector<int> g[MAXV];
int pre[MAXV] = {0};
int low[MAXV] = {0};
map<int, int> scc_v_to_no;
vector<int> scc_no_to_v[MAXV];
stack<int> s;

void DFS(int u) {
  int child_num = 0;
  ++dfs_clock;
  pre[u] = dfs_clock;
  low[u] = dfs_clock;
  s.push(u);
  for (int v: g[u]) {
    if (!pre[v]) {
      DFS(v);
      low[u] = min(low[u], low[v]);
    } else if (scc_v_to_no.find(v) == scc_v_to_no.end()) {
      low[u] = min(low[u], pre[v]);
    }
  }
  if (low[u] == pre[u]) {
    while (1) {
      auto x = s.top();
      s.pop();
      scc_v_to_no.emplace(x, scc_count);
      scc_no_to_v[scc_count].push_back(x);
      if (x == u) {
        ++scc_count;
        break;
      }
    }
  }
}

void SCC() {
  for (int i = 0; i < v ; ++i) {
    if (!pre[i]) {
      DFS(i);
    }
  }
}

int main() {
  scanf("%d %d", &v, &e);
  for (int i = 0; i < e; ++i) {
    int s, t;
    scanf("%d %d", &s, &t);
    g[s].push_back(t);
  }

  SCC();

  int q;
  scanf("%d\n", &q);
  for (size_t i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", scc_v_to_no.at(a) == scc_v_to_no.at(b));
  }

  return 0;
}

