//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

int V, E, Q, a, b;
vector<int> G[100001];
vector<int> rG[100001];
vector<int> vs;
bool used[100001];
int cmp[100001];

auto dfs(int v) -> void {
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i)
        if (!used[G[v][i]])
            dfs(G[v][i]);

    vs.push_back(v);
}

auto rdfs(int v, int k) -> void{
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++)
        if (!used[rG[v][i]])
            rdfs(rG[v][i], k);
}

/**
 * ?????£?????????????§£
 * @return ?????£???????????????????????????????????????????????§???
 */
auto scc() -> int {
    fill(used, used + V, false);
    vs.clear();
    for (int v = 0; v < V; v++) {
        if (!used[v]) dfs(v);
    }
    fill(used, used + V, false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
        if (!used[vs[i]])
            rdfs(vs[i], k++);

    return k;
}

auto main() -> signed {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    int k = scc();

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << ((cmp[a] == cmp[b]) ? 1 : 0) << endl;
    }
    return 0;
}