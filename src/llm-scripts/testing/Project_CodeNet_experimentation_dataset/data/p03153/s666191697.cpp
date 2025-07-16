#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using E = pair<ll, P>;

const ll INF = 1LL << 60;

int n;
ll D;
ll a[200005];
vector< E > edges;

void solve(int L, int R) {
    if (R - L <= 1) return;
    int mid = (R + L) / 2;

    ll lval = INF;
    int lidx = -1;
    for (int i = L; i < mid; i++) {
        ll tmp = a[i] - D * i;
        if (lval > tmp) {
            lidx = i;
            lval = tmp;
        }
    }

    ll rval = INF;
    int ridx = -1;
    for (int i = mid; i < R; i++) {
        ll tmp = a[i] + D * i;
        if (rval > tmp) {
            ridx = i;
            rval = tmp;
        }
    }

    for (int i = L; i < mid; i++) {
        edges.emplace_back(a[i] + a[ridx] + D * (ridx - i), P(i, ridx));
    }

    for (int i = mid; i < R; i++) {
        edges.emplace_back(a[i] + a[lidx] + D * (i - lidx), P(lidx, i));
    }

    solve(L, mid);
    solve(mid, R);
}

struct UnionFind {
    //各要素が属する集合の代表(根)を管理する
    //もし、要素xが根であればdata[x]は負の値を取り、-data[x]はxが属する集合の大きさに等しい
    vector<int> data;

    UnionFind(int sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        bool is_union = (x != y);
        if (is_union) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return is_union;
    }

    int find(int x) {
        if (data[x] < 0) { //要素xが根である
            return x;
        } else {
            data[x] = find(data[x]); //data[x]がxの属する集合の根でない場合、根になるよう更新される
            return data[x];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -data[find(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> D;
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(0, n);

    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    ll ans = 0;
    for (E& e : edges) {
        ll cost = e.first;
        int u = e.second.first, v = e.second.second;
        if (!uf.same(u, v)) {
            uf.unite(u, v);
            ans += cost;
        }
    }
    cout << ans << endl;
    return 0;
}