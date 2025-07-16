#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ")
#define print1(v) cout << fixed << setprecision(10) << v << "\n"
#define print2(v1, v2) cout << fixed << setprecision(10) << v1 << " " << v2 << "\n"
#define printvi(v, n) REP(iiii, n) { cout << v[iiii]; delim(iiii, n); }
#define printvii(v, h, w) REP(iiiii, h) { printvi(v[iiiii], w); }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 1e5;
int n;
vi x(maxn);
vi y(maxn);
vb used(maxn);
graph G(maxn);

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

// O(|E|log|V|)
int prim() {
    int s = 0;
    used.assign(n, false);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, s);
    int ret = 0;
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (used[v]) continue;
        used[v] = true;
        ret += p.first;
        for (auto &e : G[v]) pq.emplace(e.cost, e.to);
    }
    return ret;
}

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> n;
    REP(i, n) {
        cin >> x[i] >> y[i];
    }

    vi idx(n);
    vi idy(n);
    REP(i, n) {
        idx[i] = i;
        idy[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](int i, int j) { return x[i] < x[j]; });
    sort(idy.begin(), idy.end(), [&](int i, int j) { return y[i] < y[j]; });

    REP(i, n-1) {
        edge e;
        int s = idx[i];
        e.to = idx[i+1];
        e.cost = x[e.to] - x[s];
        G[s].push_back(e);
        swap(e.to, s);
        G[s].push_back(e);
    }
    REP(i, n-1) {
        edge e;
        int s = idy[i];
        e.to = idy[i+1];
        e.cost = y[e.to] - y[s];
        G[s].push_back(e);
        swap(e.to, s);
        G[s].push_back(e);
    }
    
    int ret = prim();

    print1(ret);
}