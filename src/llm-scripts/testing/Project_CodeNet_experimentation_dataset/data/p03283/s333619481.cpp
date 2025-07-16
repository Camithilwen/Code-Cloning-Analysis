// https://atcoder.jp/contests/abc106/tasks/abc106_d
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

// https://github.com/drken1215/algorithm/blob/master/DataStructure/binary_indexed_tree_2D.cpp
template <class Abel> struct BIT2D {
    const Abel UNITY_SUM = 0; // to be set
    vector<vector<Abel>> dat;

    BIT2D(int n = 1, int m = 1) : dat(n + 1, vector<Abel>(m + 1, UNITY_SUM)) {}
    void init(int n, int m) {
        dat.assign(n + 1, vector<Abel>(m + 1, UNITY_SUM));
    }

    /* add x on the point (a, b) */
    inline void add(int a, int b, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            for (int j = b; j < (int)dat[0].size(); j += j & -j)
                dat[i][j] = dat[i][j] + x;
    }

    inline Abel sum(int p, int q) {
        Abel res = UNITY_SUM;
        for (int i = p; i > 0; i -= i & -i)
            for (int j = q; j > 0; j -= j & -j)
                res = res + dat[i][j];
        return res;
    }

    /* a1 <= x < b1, a2 <= y < b2, 1-indexd */
    inline Abel sum(int a1, int a2, int b1, int b2) {
        return sum(b1 - 1, b2 - 1) - sum(a1 - 1, b2 - 1) - sum(b1 - 1, a2 - 1) +
               sum(a1 - 1, a2 - 1);
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) {
            for (int j = 1; j < (int)dat[0].size(); ++j)
                cout << sum(i, j, i + 1, j + 1) << ",";
            cout << endl;
        }
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    BIT2D<int> ft(N, N);
    REP(i, M) {
        int l, r;
        cin >> l >> r;
        ft.add(l, r, 1);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        // [l, r)の半開区間なので右側は+1する
        cout << ft.sum(l, l, r + 1, r + 1) << "\n";
    }

    return 0;
}
