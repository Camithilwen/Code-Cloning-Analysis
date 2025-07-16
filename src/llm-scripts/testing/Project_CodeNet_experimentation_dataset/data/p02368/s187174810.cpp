#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define rep(i, j) for(int i=0; i < (int)(j); i++)

using EdgeList = vector<vector<int>>;

// ?????£?????????????????°?????? E ????????£????????????????§£
// O(N + M) N: ????????°, M: ?????°
vector<vector<int>> strongly_connected_components(const EdgeList &E) {
    int N = E.size();
    vector<int> ord(N, -1), low(N);
    int cnt = 0;
    stack<int> stk;
    vector<bool> on_stack(N);
    vector<vector<int>> scc;    
    function<void(int, int)> dfs = [&] (int now, int pre) {
        stk.push(now);
        on_stack[now] = true;
        ord[now] = cnt++;
        low[now] = ord[now];
        for(int nxt : E[now]) {
            if(ord[nxt] < 0) {
                // not visited
                dfs(nxt, now);
                low[now] = min(low[now], low[nxt]);
            } else if(on_stack[nxt]) {
                // visited
                low[now] = min(low[now], ord[nxt]);
            } 
        }
        if(ord[now] == low[now]) {
            scc.push_back({});
            while(true) {
                int v = stk.top(); stk.pop();
                scc.back().push_back(v);
                on_stack[v] = false;
                if(v == now) break;
            }
        }
    };
    // ??£?????°????????????dfs(0)????????§OK?????????
    rep(i, N) if(ord[i] < 0) dfs(i, -1);
    return scc;
}

#define all(v) v.begin(),v.end()

struct UnionFind{
    int n;
    vector<int> p;
    UnionFind(int nn):n(nn) {
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int root(int x) {
        return p[x] == x ? x : (p[x] = root(p[x]));
    }
    void unite(int x,int y) {
        x = root(x); y = root(y);
        if(x != y) p[y] = x;
    }
    bool query(int x,int y){
        return root(x) == root(y);
    }
};

class Solver {
  public:
    bool solve() {
        int N, M; cin >> N >> M;
        EdgeList E(N);
        rep(i, M) {
            int a, b; cin >> a >> b;
            E[a].push_back(b);
        }
        auto scc = strongly_connected_components(E);
        
        UnionFind uf(N);
        for(auto &group : scc) for(int v : group) uf.unite(group.front(), v);

        int Q; cin >> Q;

        rep(i, Q) {
            int u, v; cin >> u >> v;
            cout << uf.query(u, v) << endl;
        }
        
        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Solver s;
    s.solve();
    return 0;
}