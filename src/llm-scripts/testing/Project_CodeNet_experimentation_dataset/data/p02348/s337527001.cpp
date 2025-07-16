#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

template <typename Operator>
struct LazySegmentTree {
    Operator OP;
    using NodeType = decltype(OP.NodeE);
    using FuncType = decltype(OP.FuncE);
    int length, height;
    vector<NodeType> node;
    vector<FuncType> lazy;
    
    LazySegmentTree(int n) {
        length = 1;
        height = 0;
        while (length < n) {
            length <<= 1;
            ++height;
        }
        node.resize(length << 1, OP.NodeE);
        lazy.resize(length << 1, OP.FuncE);
    }
    
    void eval(int n) {
        node[n] = OP.NodeFunc(node[n], lazy[n]);
        if (n < length) {
            lazy[(n << 1) | 0] = OP.MergeFunc(lazy[(n << 1) | 0], lazy[n]);
            lazy[(n << 1) | 1] = OP.MergeFunc(lazy[(n << 1) | 1], lazy[n]);
        }
        lazy[n] = OP.FuncE;
    }
    
    void update(int a, int b, FuncType x) {
        int l = a + length, r = b + length - 1;
        for (int i = height; i > 0; --i) {
            eval(l >> i);
            eval(r >> i);
        }
        ++r;
        while (r > l) {
            if (l & 1) {
                lazy[l] = OP.MergeFunc(lazy[l], x);
                ++l;
            }
            if (r & 1) {
                --r;
                lazy[r] = OP.MergeFunc(lazy[r], x);
            }
            l >>= 1; r >>= 1;
        }
        l = a + length; r = b + length - 1;
        while (l >>= 1) node[l] = OP.MergeNode(OP.NodeFunc(node[(l << 1) | 0], lazy[(l << 1) | 0]), OP.NodeFunc(node[(l << 1) | 1], lazy[(l << 1) | 1]));
        while (r >>= 1) node[r] = OP.MergeNode(OP.NodeFunc(node[(r << 1) | 0], lazy[(r << 1) | 0]), OP.NodeFunc(node[(r << 1) | 1], lazy[(r << 1) | 1]));
    }
    
    NodeType get(int a, int b) {
        int l = a + length, r = b + length - 1;
        for (int i = height; i >= 0; --i) {
            eval(l >> i);
            eval(r >> i);
        }
        ++r;
        NodeType vl = OP.NodeE, vr = OP.NodeE;
        while (l < r) {
            if (l & 1) vl = OP.MergeNode(vl, node[l++]);
            if (r & 1) vr = OP.MergeNode(node[--r], vr);
            l >>= 1; r >>= 1;
        }
        return OP.MergeNode(vl, vr);
    }
};

struct hoge {
    ll NodeE = 0;
    ll FuncE = INF;
    ll MergeNode(ll x, ll y) {
        return x + y;
    }
    ll MergeFunc(ll x, ll y) {
        if (y == INF) return x;
        else return y;
    }
    ll NodeFunc(ll x, ll y) {
        if (y == INF) return x;
        else return y;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    LazySegmentTree<hoge> LST(n);
    LST.update(0, n, (1LL << 31) - 1);
    REP(_, q) {
        int num;
        cin >> num;
        if (!num) {
            int s, t, x;
            cin >> s >> t >> x;
            ++t;
            LST.update(s, t, x);
        } else {
            int i;
            cin >> i;
            cout << LST.get(i, i + 1) << "\n";
        }
    }
    
    return 0;
}

