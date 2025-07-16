#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

struct edge{int to, cost;};
const int MAX_M = 2e5 + 5, INF = 1e5;
int N, M, d[MAX_M * 3];
vector<edge> G[MAX_M * 3];
map<P, int> f;

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(d, d+MAX_M*3, INF); d[s] = 0;
    pq.push(P(0, s));

    while(pq.size()){
        P p = pq.top(); pq.pop();
        int v = p.second;
        if(d[v]<p.first) continue;
        for(auto e : G[v]){
            if(d[v]+e.cost<d[e.to]){
                d[e.to] = d[v] + e.cost;
                pq.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    cin >> N >> M;
    f[P(1, 0)] = 0; f[P(N, 0)] = 1;
    int cnt = 2;
    for(int i=0;i<M;i++){
        int p, q, c; cin >> p >> q >> c;
        
        auto it1 = f.find(P(p, c)), it2 = f.find(P(q, c));
        if(it1 == f.end()) f[P(p, c)] = cnt++;
        if(it2 == f.end()) f[P(q, c)] = cnt++;
        edge e1; e1.to = f[P(q, c)]; e1.cost = 0;
        edge e2; e2.to = f[P(p, c)]; e2.cost = 0;
        G[f[P(p, c)]].push_back(e1); G[f[P(q, c)]].push_back(e2);
        
        auto it3 = f.find(P(p, 0)), it4 = f.find(P(q, 0));
        if(it3 == f.end()) f[P(p, 0)] = cnt++;
        if(it4 == f.end()) f[P(q, 0)] = cnt++;
        edge e3; e3.to = f[P(p, 0)]; e3.cost = 0;
        edge e4; e4.to = f[P(q, 0)]; e4.cost = 0;
        G[f[P(p, c)]].push_back(e3); G[f[P(q, c)]].push_back(e4);

        edge e5; e5.to = f[P(p, c)]; e5.cost = 1;
        edge e6; e6.to = f[P(q, c)]; e6.cost = 1;
        G[f[P(p, 0)]].push_back(e5); G[f[P(q, 0)]].push_back(e6);
    }

    dijkstra(f[P(1, 0)]);
    
    if(d[f[P(N, 0)]] == INF) cout << -1 << endl;
    else cout << d[f[P(N, 0)]] << endl;

    return 0;
}
