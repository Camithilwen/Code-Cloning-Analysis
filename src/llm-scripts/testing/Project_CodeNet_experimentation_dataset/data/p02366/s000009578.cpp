#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct ArticularPoint {
    int n;
    vector<vector<int>> g;
    set<int> points;
    vector<int> parent;
    vector<int> discTime;
    vector<int> lowTime;
    vector<bool> visited;
    vector<bool> isAp;
    int time = 0;
    
    ArticularPoint(int n): n(n) {
        g.assign(n, vector<int>());
        parent.assign(n, -1);
        discTime.assign(n, 0);
        lowTime.assign(n, n + 1);
        visited.assign(n, false);
        isAp.assign(n, false);
    }
    
    void addEdge(int from, int to) {
        g[from].push_back(to);
        g[to].push_back(from);
    }
    
    int solve() {
        dfs(0, -1);
        return points.size();
    } 
    
    void dfs(int u, int p) {
        discTime[u] = time++;
        lowTime[u] = discTime[u];
        visited[u] = true;
        int child = 0;
        for (int v : g[u]) {
            if (!visited[v]) {
                child++;
                parent[v] = u;
                dfs(v, u);
                lowTime[u] = min(lowTime[u], lowTime[v]);
                if (lowTime[v] >= discTime[u]) {
                    isAp[u] = true;;
                }
            }
            else if (v != p) {
                lowTime[u] = min(lowTime[u], discTime[v]);
            }
        }
        //Remove root is it has only one child
        if (p < 0 && child == 1) {
           isAp[u] = false;
        }
    }   
};

int main() {
    int n, m;
    cin >> n >> m;
    ArticularPoint ap(n);
    
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        ap.addEdge(from, to);
    }
    
    int ans = ap.solve();
    for (int i = 0; i < n; i++) {
        if (ap.isAp[i]) {
            cout << i << endl;
        }
    }
    
    return 0;
}