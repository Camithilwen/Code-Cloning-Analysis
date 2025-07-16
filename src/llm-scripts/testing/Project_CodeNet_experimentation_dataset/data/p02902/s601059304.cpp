#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

template< typename T >
struct edge {
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x) {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1), GR(N + 1);
    Edges<int> edges;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        GR[B].push_back(A);
        edges.emplace_back(A, B, -1);
    }
    if (M == 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> dist1(N + 1, INF);
    dist1[edges.begin()->src] = 0;
    dist1[edges.rbegin()->src] = 0;
    for(int i = 1; i <= N * 2; i++) {
        for(auto &e : edges) {
            if(dist1[e.src] == INF) continue;
            dist1[e.to] = min(dist1[e.to], dist1[e.src] + e.cost);
        }
    }
    vector<int> dist2(N + 1); copy(dist1.begin(), dist1.end(), dist2.begin());
    for(int i = 1; i <= N * 2; i++) {
        for(auto &e : edges) {
            if(dist2[e.src] == INF) continue;
            dist2[e.to] = min(dist2[e.to], dist2[e.src] + e.cost);
        }
    }
    if (dist1 == dist2) {
        cout << -1 << endl;
        return 0;
    }
    int s = 0, count = INF;
    vector<map<int, int>> res(N + 1);
    for (int i = 1; i <= N; i++) {
        vector<bool> check(N + 1, false);
        queue<int> explore;
        vector<int> dist(N + 1, INF);
        explore.push(i);
        dist[i] = 0;
        check[i] = true;
        while (!explore.empty()) {
            int now = explore.front();
            explore.pop();
            for (auto next : G[now]) {
                if (dist[next] > dist[now] + 1) {
                    dist[next] = dist[now] + 1;
                    res[i][next] = now;
                }
                if (check[next]) continue;
                check[next] = true;
                explore.push(next);
            }
            if (now == i) dist[i] = INF;
        }
        if (dist[i] < count) {
            s = i;
            count = dist[i];
        }
    }
    vector<int> ans = {s};
    int next = res[s][s];
    while (next != s) {
        ans.push_back(next);
        next = res[s][next];
    }
    cout << ans.size() << endl;
    for (auto temp : ans) cout << temp << endl;
}