#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

class Dijkstra {
    private:
        vector< vector<LLP> > G;
        vector<long long> cost;
        vector<long long> par;
        priority_queue<LLP, vector<LLP>, greater<LLP> > que;

    public:
        Dijkstra(long long n, vector< vector<long long> > g, long long s);
        long long getCost(long long target);
        vector< vector<long long> > getPath(long long target);
};

// n: |V|
// g: [point_from, point_to, cost] (directed graph)
// s: start point
Dijkstra::Dijkstra(long long n, vector< vector<long long> > g, long long s) {
    for (long long i = 0; i < n; i++) {
        G.push_back(vector<LLP>());
        cost.push_back(-1);
        par.push_back(-1);
    }

    // create adj-Graph
    for (long long i = 0; i < g.size(); i++) {
        G[g[i][0]].push_back(make_pair(g[i][1], g[i][2]));
    }

    // initialize
    cost[s] = 0;
    par[s] = s;
    que.push(make_pair(cost[s], s));

    while (!que.empty()) {
        LLP p = que.top();
        que.pop();

        if (cost[p.second] < p.first) continue;
        for (int i = 0; i < G[p.second].size(); i++) {
            if (cost[G[p.second][i].first] < 0 || cost[G[p.second][i].first] > cost[p.second] + G[p.second][i].second) {
                cost[G[p.second][i].first] = cost[p.second] + G[p.second][i].second;
                par[G[p.second][i].first] = p.second;
                que.push(make_pair(cost[G[p.second][i].first], G[p.second][i].first));
            }
        }
    }
}

// returns the minimum cost from the start point to the target.
// (if there is no path to the target, this returns -1.)
// (if the target is the start point, this returns 0.)
long long Dijkstra::getCost(long long target) {
    return cost[target];
}


// returns a list of path: Array of [point_from, point_to, cost].
// (if there is no path to the target or the target is the start point, this returns an empty vector.)
vector< vector<long long> > Dijkstra::getPath(long long target) {

    vector< vector<long long> > reversePath = vector< vector<long long> >(0);

    if (cost[target] <= 0) return reversePath;
    
    long long now_p = target;
    while (par[now_p] != now_p) {
        vector<long long> temp(3);
        temp[0] = par[now_p];
        temp[1] = now_p;
        temp[2] = cost[now_p] - cost[par[now_p]];
        reversePath.push_back(temp);
        now_p = par[now_p];
    }

    vector< vector<long long> > path = vector< vector<long long> >(0);
    for (long long i = reversePath.size() - 1; i >= 0; i--) path.push_back(reversePath[i]);

    return path;
}

int main() {

    int N, Q, K;
    cin >> N;
    vector<vector<ll>> g;
    rep(i,N-1) {
        vector<ll> e(3);
        cin >> e[0] >> e[1] >> e[2];
        e[0]--;
        e[1]--;
        g.push_back(e);
        swap(e[0], e[1]);
        g.push_back(e);
    }

    cin >> Q >> K;
    K--;
    Dijkstra tree(N, g, K);

    rep(i,Q) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << tree.getCost(x) + tree.getCost(y) << endl;
    }
    
    return 0;
}