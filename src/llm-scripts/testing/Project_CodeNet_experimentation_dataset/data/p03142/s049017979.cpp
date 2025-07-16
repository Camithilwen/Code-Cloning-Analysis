#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



int N, M;
bool seen[110000];
using Graph = vector<vector<int>>;

void dfs(int v, const Graph& G, vector<int>& order) {
  seen[v] = true;

  for (auto nv : G[v]) {
    if (seen[nv]) continue; 
    dfs(nv, G, order);
  }

  order.push_back(v);
}

int main () {
  cin >> N >> M;
  Graph G(N+1);
  Graph Gyaku(N+1);

  Rep(i, N-1+M) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    Gyaku[b].push_back(a);
  }

  vector<int> order;
  rep(i, N) {
    if (seen[i]) continue;
    dfs(i, G, order);
  }

  reverse(All(order));

  map<int, int> mp;

  rep(i, N) {
    mp[order[i-1]] = i;
    //cout << order[i-1] << "\n";
  }

  rep(i, N) {
    if (mp[i] == 1) {
      cout << 0 << "\n";
    } else {
      int tmp = 0;
      int tmp_p = 0;
      for (auto nv: Gyaku[i]) {
        //cout << " " << nv << " " << mp[nv] << "\n";

        if (mp[nv] > tmp) {
          tmp = mp[nv];
          tmp_p = nv;
        }
      }

      cout << tmp_p << "\n";
    }
  }

}