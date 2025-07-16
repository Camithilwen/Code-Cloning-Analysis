#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

#define LOG_MAX 30
// 1つ先が無い(木の根など)場合、値を負かn以上とする
template <typename T>
class Doubling {
    const size_t n;
    vector<vector<T>> next;
public:
    Doubling() {}
    Doubling(vector<T> first_row) 
    : n(first_row.size()), 
      next(LOG_MAX, vector<T>(n)) {
        copy(first_row.begin(), first_row.end(), next[0].begin());
        for (size_t i=1; i<LOG_MAX; i++) {
            for (size_t j=0; j<n; j++) {
                next[i][j] = (
                    (0 <= next[i-1][j] && (size_t)next[i-1][j] < n)
                    ? next[i-1][(size_t)next[i-1][j]]
                    : next[i-1][j]
                );
            }
        }
    }

    T query(T i, int step=1) {
        for (int k=LOG_MAX-1; k>=0; k--) {
            if ((step >> k) & 1) i = next[(size_t)k][(size_t)i];
            if (i < 0 || n <= (size_t)i) break;
        }
        return i;
    }
};

int main() {
    int n, q;
    cin >> n;
    long x[n], l;
    for (auto &xi:x) cin >> xi;
    cin >> l >> q;
    vector<int> first_row(n);
    for (int i=0; i<n; i++) {
        int ub = upper_bound(x+i, x+n, x[i] + l) - x;
        first_row[i] = ub - 1;
    }
    Doubling<int> db(first_row);
    for (int i=0, a, b; i<q; i++) {
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        int l=0, r=n-1;
        while (r - l > 1) {
            int m = (l + r + 1) / 2,
                dest = db.query(a, m);
            if (b > dest) l = m;
            else r = m; 
        }
        cout << r << '\n';
    }
    return 0;
}
