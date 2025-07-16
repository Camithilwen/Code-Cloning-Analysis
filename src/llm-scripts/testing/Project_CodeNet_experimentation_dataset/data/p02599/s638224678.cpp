#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class Abel> struct BIT {
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;                     // to be set
    
    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) { for (int iter = 0; iter < 2; ++iter) dat[iter].assign(n + 1, UNITY_SUM); }
    
    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(int p, int a, Abel x) {
        for (int i = a; i < (int)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(int a, int b, Abel x) {
        sub_add(0, a, x * -(a - 1)); sub_add(1, a, x); sub_add(0, b, x * (b - 1)); sub_add(1, b, x * (-1));
    }
    
    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(int p, int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i) res = res + dat[p][i];
        return res;
    }
    inline Abel sum(int a, int b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat[0].size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main() {
    int N; cin >> N;
	int Q; cin >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    vector<int> lefts(Q), rights(Q), ids(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> lefts[i] >> rights[i];
        --lefts[i];
        ids[i] = i;
    }
    sort(ids.begin(), ids.end(), [&](int i, int j) {
            return rights[i] < rights[j];});

    BIT<int> bit(N+5);
    vector<int> prev(1100000, -1);
    vector<int> res(Q, 0);
    int r = 0;
    for (auto i : ids) {
        for (; r < rights[i]; ++r) {
            bit.add(prev[a[r]]+2, r+2, 1);
            prev[a[r]] = r;
        }
        int tmp = bit.sum(lefts[i]+1, lefts[i]+2);
        res[i] = max(res[i], tmp);
    }
    for (int i = 0; i < Q; ++i) cout << res[i] << endl;
}
