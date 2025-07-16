//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

class SCC {
    private:
        int V;
        int E;

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

    public:
        SCC(int V, int E)
            : V(V), E(E) { }

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

        auto add_edge(int s, int t) {
            G[s].push_back(t);
            rG[t].push_back(s);
        }

        auto get_cmp(int a) -> int {
            return cmp[a];
        }

        auto is_union_cmp(int a, int b) -> bool {
            return cmp[a] == cmp[b];
        }
};



auto main() -> signed {
    int a, b;
    int V, E;
    cin >> V >> E;
    SCC scc(V, E);
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        scc.add_edge(a, b);
    }
    int k = scc.scc();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << scc.is_union_cmp(a, b) << endl;
    }
    return 0;
}