#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, int>;
using E = pair<ll, pair<int, int> >;

const ll INF = 1LL << 60;

template <typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T INITIAL_VALUE;

    //使うときは、この2つを適宜変更する
    static T merge(T x, T y);
    void updateNode(int k, T x);

    SegmentTree(int size, T initial_value) {
        n = 1;
        INITIAL_VALUE = initial_value;
        while (n < size) n *= 2;
        data.resize(2 * n - 1, INITIAL_VALUE);
    }

    T getLeaf(int k) {
        return data[k + n - 1];
    }

    void update(int k, T x) {
        k += n - 1; //葉の節点
        updateNode(k, x);
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = merge(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    //区間[a, b)に対するクエリに答える
    //k:節点番号, [l, r):節点に対応する区間
    T query(int a, int b) {
        T vl = INITIAL_VALUE, vr = INITIAL_VALUE;
        for (int l = a + n, r = b + n; l != r; l >>= 1, r >>= 1) {
            if (l & 1) vl = merge(vl, data[l++ - 1]);
            if (r & 1) vr = merge(vr, data[--r - 1]);
        }
        return merge(vl, vr);
    }
};

//使うときは以下2つを変更
template <typename T>
T SegmentTree<T>::merge(T x, T y) {
    return min(x, y);
}

template <typename T>
void SegmentTree<T>::updateNode(int k, T x) {
    data[k] = x;
}

int n;
ll D;
ll a[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> D;
    vector< vector<int> > vs(n);
    vector<int> root(n), idxs(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vs[i].push_back(i);
        root[i] = i;
        idxs[i] = i;
    }
    
    SegmentTree<P> st1(n, P(INF, -1)), st2(n, P(INF, -1));
    for (int i = 0; i < n; i++) {
        st1.update(i, P(a[i] - D * i, i));
        st2.update(i, P(a[i] + D * i, i));
    }

    int max_size = 1;
    ll ans = 0;

    while (max_size < n) {
        vector< E > es;
        for (int i : idxs) {
            if (vs[i].empty()) continue;
            for (int j : vs[i]) {
                st1.update(j, P(INF, -1));
                st2.update(j, P(INF, -1));
            }

            P p(INF, -1);
            for (int j : vs[i]) {
                P q1 = st1.query(0, j);
                q1.first += a[j] + D * j;
                P q2 = st2.query(j + 1, n);
                q2.first += a[j] - D * j;
                P p2 = min(q1, q2);
                if (p > p2) p = p2;
            }

            for (int j : vs[i]) {
                st1.update(j, P(a[j] - D * j, j));
                st2.update(j, P(a[j] + D * j, j));
            }

            if (p.second == -1) continue;
            es.emplace_back(p.first, make_pair(i, p.second));
        }

        for (E& e : es) {
            int ri = root[e.second.first];
            int r = root[e.second.second];
            if (ri == r) continue;

            ans += e.first;
            if (vs[ri].size() >= vs[r].size()) {
                for (int j : vs[r]) {
                    vs[ri].push_back(j);
                    root[j] = ri;
                }
                vs[r].clear();
                max_size = max(max_size, (int)vs[ri].size());
            } else {
                for (int j : vs[ri]) {
                    vs[r].push_back(j);
                    root[j] = r;
                }
                vs[ri].clear();
                max_size = max(max_size, (int)vs[r].size());
            }
        }
    }
    cout << ans << endl;
    return 0;
}