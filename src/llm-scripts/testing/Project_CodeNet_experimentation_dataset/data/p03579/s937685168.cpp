#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> data;
    int sz;
    UnionFind(int sz) : data(sz, -1), sz(sz) { }
    bool unionSet(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; sz--;
        return true;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
    int size() { return sz; }
};

int main() {
    int n, m; cin >> n >> m;
    UnionFind uf(n * 2);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        uf.unionSet(a, b + n);
        uf.unionSet(a + n, b);
    }
    long long all = 0;
    if (uf.findSet(0, n)) {
        all = 1LL * n * (n - 1) / 2;
    } else {
        for (int i = 0; i < n; i++) all += uf.findSet(0, i);
        all *= n - all;
    }
    cout << all - m << endl;
    return 0;
}
