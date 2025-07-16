#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

struct SccKosaraju {
    int n;
    vector<vector<int>> g;
    vector<vector<int>> rg;
    vector<bool> visited;
    vector<int> sccno;
    int sccCount = 0;
    vector<int> s;
    
    
    SccKosaraju(int n): n(n) {
        g.assign(n, vector<int>());
        rg.assign(n, vector<int>());
        visited.assign(n, false);

        sccno.assign(n, -1);
    }
    
    void addEdge(int from, int to) {
        g[from].push_back(to);
        rg[to].push_back(from);
    }
    
    void solve() {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (sccno[s[i]] == -1) {
                sccCount++;
                dfs2(s[i]);
            }
        }
    } 
    
    bool sameScc(int u, int v) {
        return sccno[u] == sccno[v];
    }
    
    void dfs1(int u) {
        visited[u] = true;
        for (int v : g[u]) {
            if (!visited[v]) {
                dfs1(v);
            }
        }
        s.push_back(u);
    } 
    
    void dfs2(int u) {
        sccno[u] = sccCount;
        for (int v : rg[u]) {
            if (sccno[v] == -1) {
                dfs2(v);
            }
        }
    }   
};

int main() {
    int n, m;
    cin >> n >> m;
    SccKosaraju scc(n);
    
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        scc.addEdge(from, to);
    }
 
    scc.solve();
    
//    for (int i = 0; i < n; i++) {
//        cout << i << " " << scc.sccno[i] << endl;
//    }
    
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        cout << (scc.sameScc(u, v)? 1 : 0) << endl;
    }
    
    return 0;
}