#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, q, k;
vector<vector<pair<lli, lli>>> g;
vector<lli> dist;
vector<lli> x, y;

void dfs(lli x, lli d){
    dist[x] = d;
    for(auto i : g[x]){
        if(dist[i.second] >= 0) continue;
        dfs(i.second, lli(dist[x]+i.first));
    }
}

int main(void){
    cin >> n;
    g.resize(n);
    dist.assign(n, -1);
    rep(i, n-1){
        lli a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    cin >> q >> k;
    k--;
    x.resize(q);
    y.resize(q);
    rep(i, q){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    dist[k] = 0;
    dfs(k, 0);
    rep(i, q){
        cout << dist[x[i]]+dist[y[i]] << endl;
    }
    return 0;
}
