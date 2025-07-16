#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define MOD 1000000007

using namespace std;

using ll = long long;

ll solve() {

    int H, W;
    cin >> H >> W;
    vector<int> A(H), B(W);
    set<int> As, Bs;
    REP(i, H) {
        cin >> A[i];
        --A[i];
        As.insert(A[i]);
    }
    REP(i, W) {
        cin >> B[i];
        --B[i];
        Bs.insert(B[i]);
    }

    if (As.size() < H || Bs.size() < W) {
        return 0;
    }

    int n_used_rows = 0;
    int n_used_cols = 0;
    ll result = 1;
    RREP(x, H * W) {
        int n_filled = H * W - 1 - x;
        bool inA = As.count(x) > 0;
        bool inB = Bs.count(x) > 0;
        int n_ways;
        if (inA && inB) {
            n_ways = 1;
            ++n_used_rows;
            ++n_used_cols;
        } else if (inA && !inB) {
            n_ways = n_used_cols;
            ++n_used_rows;
        } else if (!inA && inB) {
            n_ways = n_used_rows;
            ++n_used_cols;
        } else {
            n_ways = n_used_rows * n_used_cols - n_filled;
            if (n_ways <= 0) return 0;
        }
        result = (result * n_ways) % MOD;
    }
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << solve() << endl;

    return 0;
}
