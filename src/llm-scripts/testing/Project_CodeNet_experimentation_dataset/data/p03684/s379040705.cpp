/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.20 03:18:30
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;


class UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int n) {
        par.resize(n, -1);
    }
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (size(rx) < size(ry)) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    int n;cin >> n;
    vector<pair<int,int>> p(n),q(n);
    for (int i = 0; i < n; i++) {
        int a,b;cin >> a >> b;
        p[i].first = a;
        p[i].second = q[i].second = i;
        q[i].first = b;
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    UnionFind uf(n);
    typedef tuple<int,int,int> T;
    priority_queue<T,vector<T>,greater<T>> pq;
    for (int i = 0; i < n-1; i++) {
        pq.push(make_tuple(p[i+1].first - p[i].first,p[i+1].second,p[i].second));
        pq.push(make_tuple(q[i+1].first - q[i].first,q[i+1].second,q[i].second));
    }
    ll ans = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int x = get<1>(t);
        int y = get<2>(t);
        if (!uf.same(x,y)) {
            ans += get<0>(t);
            uf.unite(x,y);
        }
    }
    cout << ans << endl;
    return 0;
}