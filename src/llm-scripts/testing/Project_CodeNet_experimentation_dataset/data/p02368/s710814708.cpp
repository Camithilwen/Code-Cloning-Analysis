#include <vector>
#include <algorithm>

using namespace std;

void scc_dfs(int at, int &cnt, vector<int> &inum, vector<bool> &used, const vector<vector<int>> &graph)
{
    used[at] = true;
    for (int ne : graph[at]) {
        if (!used[ne]) scc_dfs(ne, cnt, inum, used, graph);
    }
    inum[cnt] = at;
    cnt++;
}

#include <iostream>
void scc_rdfs(int at, vector<int> &cs, vector<bool> &used, const vector<vector<int>> &inv)
{
    used[at] = true;
    cs.push_back(at);
    for (int ne : inv[at]) {
        if (!used[ne]) scc_rdfs(ne, cs, used, inv);
    }
}


vector<vector<int>> strongly_connected_components(const vector<vector<int>> &graph)
{
    const int V = graph.size();

    int cnt = 0;
    vector<int> inum(V);
    vector<bool> used(V);
    for (int i = 0; i < V; i++) {
        if (!used[i]) scc_dfs(i, cnt, inum, used, graph);
    }

    vector<vector<int>> inv(V);
    for (int i = 0; i < V; i++){
        for (int v : graph[i]) {
            inv[v].push_back(i);
        }
    }
    fill(used.begin(), used.end(), false);
    vector<vector<int>> ret;
    for (int i = V - 1; i >= 0; i--) {
        vector<int> cs;
        if (!used[inum[i]]) scc_rdfs(inum[i], cs, used, inv);
        ret.push_back(cs);
    }
    return ret;
}

#include <iostream>

int main()
{
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    int s, t;
    for (int i = 0; i < E; i++) {
        cin >> s >> t;
        graph[s].push_back(t);
    }

    auto res = strongly_connected_components(graph);
    vector<int> num(V);
    for (int i = 0; i < res.size(); i++) {
        for (int v : res[i]) {
            num[v] = i;
        }
    }

    int Q;
    cin >> Q;
    int u, v;
    for (int i = 0; i < Q; i++) {
        cin >> u >> v;
        cout << (num[u] == num[v]) << endl;
    }
}