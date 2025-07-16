#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;



const int MAX_V = 10010;
int V;
int cmp[MAX_V]; // components of each vertex
bool used[MAX_V];
vector<int> g[MAX_V], rg[MAX_V], ng[MAX_V], vs;

void add_edge(int from, int to) {
    g[from].push_back(to);
    rg[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for (int nv: g[v]) {
        if (!used[nv]) dfs(nv);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int nv: rg[v]) {
        if (!used[nv]) rdfs(nv, k);
    }
}

// return number of components
int scc() {
    memset(used, false, sizeof(used));
    vs.clear();
    for (int v = 0; v < V; v++) {
        if (!used[v]) dfs(v);
    }
    memset(used, false, sizeof(used));
    int k = 0;
    for (int i = vs.size()-1; i >= 0; i--) {
        if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}

void new_graph(int k) {
    for (int v = 0; v < V; v++) {
        for (int nv: g[v]) {
            int x = cmp[v];
            int y = cmp[nv];
            if (x == y) continue;
            ng[x].push_back(y);
        }
    }
}


int main() {
    int e; cin >> V >> e;
    rep(i, e) {
        int s, t; cin >> s >> t;
        add_edge(s, t);
    }

    scc();

    int q; cin >> q;
    rep(i, q) {
        int u, v; cin >> u >> v;
        cout << (cmp[u] == cmp[v] ? 1 : 0) << endl;
    }


    return 0;
}
