#define _CRT_SECURE_NO_WARNINGS
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(c) begin(c), end(c)
#define range(i,a,b) for(int i = a; i < (int)(b); i++)
#define rep(i,b) range(i,0,b)
#define eb emplace_back
typedef long long ll;
auto const inf = numeric_limits<ll>::max()/4;

using Weight = ll;
using Capacity = int;
struct Edge {
    int src, dst; Weight weight;
    Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

vector<Weight> dijkstra(const Graph &g, int s){
    const Weight inf = numeric_limits<Weight>::max()/4;
    typedef tuple<Weight,int> State;
    priority_queue<State> q;
    vector<Weight> dist(g.size(), inf);
    dist[s] = 0; q.emplace(0,s);
    while (q.size()) {
        Weight d; int v;
        tie(d,v) = q.top(); q.pop(); d *= -1;
        /* if(v == t) return d; */
        if (dist[v] < d) continue;
        for(auto & e : g[v]){
            if (dist[e.dst] > dist[v] + e.weight) {
                dist[e.dst] = dist[v] + e.weight;
                q.emplace(-dist[e.dst], e.dst);
            }
        }
    }
    return dist;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int V,E,r;
    while(cin >> V >> E >> r){
        Graph g(V);
        rep(i,E){
            int a,b,c;
            cin >> a >> b >> c;
            g[a].eb(a,b,c);
        }
        vector<Weight> dist = dijkstra(g,r);
        for(int i = 0; i < (int)dist.size(); i++){
            if(dist[i] == inf) cout << "INF";
            else cout << dist[i];
            cout << endl;
        }
    }
}