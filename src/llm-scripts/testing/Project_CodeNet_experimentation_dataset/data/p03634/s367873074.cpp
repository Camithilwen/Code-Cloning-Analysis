#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const double pi = acos(-1);
 
struct Edge {
    ll to, cost;
    Edge(ll to, ll cost):to(to),cost(cost) {}
};
 
struct Data {
    ll v, x;  // いまいる頂点v, 進んだ距離x
    Data(ll v, ll x):v(v),x(x) {}
    bool operator<(const Data& hoge) const {
        return x > hoge.x;
    }
};
 
int main() {
    ll n;
    cin >> n;
    
    vector<vector<Edge>> G(n);
    rep(i, n-1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;  b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
 
    ll q, sv;
    cin >> q >> sv;
    sv--;
 
    vl dp(n, INF);
    priority_queue<Data> Q;
    auto push = [&](ll v, ll x) {
        if(dp[v] <= x) {
            return;
        }
        dp[v] = x;
        Q.emplace(v, x);
    };
    
    // ダイクストラ法。計算量はO((V+E)*log(V))
    push(sv, 0);
    while(!Q.empty()) {
        Data hoge = Q.top();  Q.pop();
        ll v = hoge.v, x = hoge.x;
        if(dp[v] != x) {
            continue;
        }
        for(Edge e : G[v]) {
            push(e.to, x + e.cost);
        }
    }
 
    rep(i, q) {
        ll x, y;
        cin >> x >> y;
        x--;  y--;
        out(dp[x] + dp[y]);
    }
 
    re0;
}