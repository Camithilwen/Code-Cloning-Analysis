#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
using ll = long long;

using Weight = int;
using Capacity = int;
struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

vector<int> articulationPoint(const Graph& g){
    int n = g.size(), idx;
    vector<int> low(n), ord(n), art;
    function<void(int)> visit = [&](int v){
        low[v] = ord[v] = ++idx;
        for(auto &e : g[v]){
            int w = e.dst;
            if(ord[w] == 0){
                visit(w);
                low[v] = min(low[v], low[w]);
                if((ord[v] == 1 && ord[w] != 2) ||
                   (ord[v] != 1 && low[w] >= ord[v])) art.push_back(v);
            } else low[v] = min(low[v], ord[w]);
        }
    };
    for(int u = 0; u < n; u++) if(ord[u] == 0){ idx = 0; visit(u); }
    return art;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin >> n >> m){
        Graph g(n);
        rep(i,m){
            int a,b;
            cin >> a >> b;
            g[a].emplace_back(a,b,0);
            g[b].emplace_back(b,a,0);
        }
        vector<int> arts = articulationPoint(g);
        sort(all(arts));
        auto last = unique(all(arts));
        for(auto it = arts.begin(); it != last; ++it) cout << *it << '\n';
    }
}