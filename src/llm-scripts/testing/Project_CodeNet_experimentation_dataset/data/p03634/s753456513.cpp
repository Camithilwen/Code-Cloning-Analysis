#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge {
	ll to;     // 辺の行き先
	ll weight; // 辺の重み
	Edge(ll t, ll w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main() {

    // 頂点数と辺数
    ll n, m; cin >> n;
    m = n - 1;

    // グラフ入力受取 (ここでは重み付き無向グラフを想定)
    Graph G(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }

    ll q, k; cin >> q >> k;
    k--;

    // BFS のためのデータ構造
    vector<ll> dist(n, -1); // 全頂点を「未訪問」に初期化
    queue<Edge> que;

    // 初期条件 (頂点 k を初期ノードとする)
    dist[k] = 0;
    que.push(Edge(k, 0)); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        Edge v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (Edge new_v : G[v.to]) {
            if (dist[new_v.to] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 new_v について距離情報を更新してキューに追加する
            dist[new_v.to] = dist[v.to] + new_v.weight;
            que.push(new_v);
        }
    }

    for (ll i = 0; i < q; i++) {
        ll x, y; cin >> x >> y;
        x--;
        y--;
        cout << dist[x] + dist[y] << endl;
    }
    return 0;
}