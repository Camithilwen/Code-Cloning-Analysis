#include <bits/stdc++.h>
using namespace std;
using edge = pair<int, long long>;
using Graph = vector<vector<edge>>;
template<class T> inline bool chmax(T& a,T b)
{if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a,T b)
{if (a > b) {a = b; return true;} return false;}
const long long INF = 1e12;

vector<long long> dijkstra(const Graph &G, int s){
    using Pi = pair<long long, int>;
// 最終的に最短経路を保持する配列, INFで初期化
    vector<long long> dist(G.size(), INF); 
// そこまでの距離, 頂点を保持する優先度付きキュー
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    dist[s] = 0; que.emplace(dist[s], s);
// キューが空になるまで(max V 回)
    while(!que.empty()){
        long long sum_dist; int node;
// キューから取り出された時点で頂点が確定
        tie(sum_dist, node) = que.top(); que.pop();
// それより短い経路が分かっているときはcontinue(枝刈り)
        if (dist[node] < sum_dist) continue;
// 確定した頂点から到達できる頂点を探索
        for (auto &e : G[node]) {
            int next_node; long long dis;
            tie(next_node, dis) = e;
// 最短距離が更新されたときだけキューに追加
            if (chmin(dist[next_node], dist[node] + dis)) {
                que.emplace(dist[next_node], next_node);
            }
        }
    }
    return dist;
}

int main(){
    int N, K, Case;
    Graph G;
    vector<vector<long long>> dist;
    while(true){
        cin >> N >> K; if(N == 0 && K == 0)break;
        
        G.assign(N, vector<edge>());
        dist.assign(N, vector<long long>(N, INF));
        
        for (int i = 0; i < K; i++) {
            cin >> Case;
            if (Case == 0) {
                int s, g; cin >> s >> g; s--; g--;
                dist[s] = dijkstra(G, s);
                long long ans = dist[s][g];
                if (ans == INF) ans = -1;
                cout << ans << endl;
            } else {
                int a, b; long long c;
                cin >> a >> b >> c; a--; b--;
                G[a].push_back(make_pair(b, c));
                G[b].push_back(make_pair(a, c));
            }
        }
    }
    return 0;
}
