#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pll> vp;
typedef vector<ll> vll;

const int MAX_V = 10000;

int V, E;
vi G[MAX_V];
vi rG[MAX_V];
vi vs;
bool used[MAX_V];
int cmp[MAX_V];

void addEdge(int from, int to) {
    G[from].emplace_back(to);
    rG[to].emplace_back(from);
}

void dfs(int v) {
    used[v] = true;
    rep(i, G[v].size()) {
        if (!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.emplace_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    rep(i, rG[v].size()) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
    vs.emplace_back(v);
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    rep(v, V) {
        if (!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> V >> E;
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        addEdge(s, t);
    }

    scc();

    int Q;
    cin >> Q;
    rep(i, Q) {
        int u, v;
        cin >> u >> v;
        cout << (cmp[u] == cmp[v]) << endl;
    }

}