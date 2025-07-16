#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int dfs(int now,vec<vec<int>> &G, vec<int> &tpl, vec<bool> &visited){
    if(tpl[now] != -1) return tpl[now];
    if(tpl[now] == -1 && visited[now]) return -1;
    visited[now] = true;

    if(G[now].size() == 0) {
        tpl[now] = 1;
        return 1;
    }

    int tmpOrder = -1;
    for(auto e:G[now]){
        int tmp = dfs(e,G,tpl,visited);
        if(tmp == -1) return -1;
        tmpOrder = max(tmpOrder,tmp+1);
    }
    tpl[now] = tmpOrder;
    return tpl[now];
}

vector<int> topological_sort(vec<vec<int>> &G){
    int N = G.size();
    vec<int> topolo(N,-1);
    vec<bool> visited(N,false);
    rep(i,N) dfs(i,G,topolo,visited);
    // {-1,-1,-1,…} の時はトポロジカルソート不可
    return topolo;
}

int main() {
    int N;
    cin >> N;
    vec<vec<int>> A(N, vec<int>(N - 1));
    rep(i, N) rep(j, N - 1) {
        cin >> A[i][j];
        --A[i][j];
    }
    vec<vec<int>> id(N, vec<int>(N, -1));
    int now = 0;
    rep(i, N) rep(j, N) {
        if (i == j || i > j) continue;
        id[i][j] = now, ++now;
    }
    
    vec<vec<int>> games(N,vec<int>(N-1));
    rep(i, N) rep(j, N - 1) {
        int me = i;
        int vs = A[i][j];
        if (me > vs) swap(me, vs);
        games[i][j] = id[me][vs];
    }
    
    vec<vec<int>> G(now,vec<int>());
    rep(i,N)rep(j,N-2){
        G[games[i][j+1]].push_back(games[i][j]);
    }

    vec<int> a = topological_sort(G);
    int ans = 0;
    for(auto e:a) {
        if(e==-1) {
            cout << -1 << endl;
            return 0;
        }
        ans= max(ans,e);
    }
    cout << ans << endl;
}