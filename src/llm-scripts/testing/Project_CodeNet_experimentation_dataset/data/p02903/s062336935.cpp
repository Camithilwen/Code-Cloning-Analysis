#include <bits/stdc++.h>

using namespace std;

#ifdef KACTL
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
#endif
#define all(x) begin(x), end(x)

using ll = int64_t;
using ld = long double;
using pii = pair<int32_t, int32_t>;
using vi = vector<int32_t>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    /* h = w, a = b
     * do the jagged thing
     *
     * XX.
     * .XX
     * X.X
     *
     * XX..
     * .XX.
     * ..XX
     * X..X
     *
     *
     * some can be 1s and some can be zeros
     * 2 4 1 1
     *
     * 3 3 1 1
     */

    vector<string> res(h, string(w, '0'));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            res[i][j] ^= (i < b) ^ (j < a);
        }
    }

    for (auto& row : res)
        cout << row << '\n';

    return 0;
}
