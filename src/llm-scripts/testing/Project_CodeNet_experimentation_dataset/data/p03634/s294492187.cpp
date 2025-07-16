#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;

struct Edge{
    /*辺の情報を入れる構造体で行き先とコストを表している*/
    int to;
    ll cost;
    Edge(int to, ll cost) : to(to), cost(cost) {}
};

vector<Edge> g[100005];
vector<ll> dist(100005);

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v.to == p) continue;
        dist[v.to] = dist[u] + v.cost;
        dfs(v.to, u);
    }
}

int main(void){
    int n;
    cin>>n;
    rep(i, n-1){
        int a, b;
        ll c;
        cin>>a>>b>>c;
        --a;--b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }
    int q, k;
    cin>>q>>k;
    --k;
    vector<pair<int, int> > v(q);
    rep(i, q){
        int x, y;
        cin>>x>>y;
        --x;--y;
        v[i] = make_pair(x, y);
    }
    rep(i, n) dist[i] = INF;
    dist[k] = 0;
    dfs(k, -1);
    rep(i, q){
        cout<<dist[v[i].first] + dist[v[i].second]<<endl;
    }
    return 0;
}