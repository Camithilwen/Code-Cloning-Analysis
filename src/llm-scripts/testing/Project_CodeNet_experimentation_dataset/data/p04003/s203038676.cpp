#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using namespace std;

template<class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> t(m);
    vector<P> v;
    for (int i = 0; i < m; ++i) {
        int p, q, c;
        scanf("%d %d %d", &p, &q, &c);
        t[i] = make_tuple(p-1, q-1, c);
        v.emplace_back(p-1, c);
        v.emplace_back(q-1, c);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto s = v.size();
    vector<vector<P>> G(s+n);
    auto getidx = [&](P a){ return lower_bound(v.begin(), v.end(), a)-v.begin();};
    for (auto &&i : t) {
        int p, q, c;
        tie(p, q, c) = i;
        auto x = getidx(P(p, c)), y = getidx(P(q, c));
        G[x].emplace_back(y, 0);
        G[y].emplace_back(x, 0);
        G[x].emplace_back(p+s, 1);
        G[p+s].emplace_back(x, 1);
        G[y].emplace_back(q+s, 1);
        G[q+s].emplace_back(y, 1);
    }
    vector<int> d(s+n, INF<int>);
    d[s] = 0;
    deque<P> Q;
    Q.emplace_front(0, s);
    while (!Q.empty()){
        int dist, u;
        tie(dist, u) = Q.front(); Q.pop_front();
        if(dist > d[u]) continue;
        for (auto &&e : G[u]) {
            int to, c;
            tie(to, c) = e;
            if(d[to] > d[u]+c){
                d[to] = d[u]+c;
                if(c == 0) Q.emplace_front(d[u], to);
                else Q.emplace_back(d[u]+1, to);
            }
        }
    }
    cout << (d[s+n-1] == INF<int> ? -1 : d[s+n-1]/2) << "\n";
    return 0;
}
