// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(2);
    cin >> v[0] >> v[1];
    int ans = 0;
    if (v[0] == 1 && v[1] == 1) {
        ans += 400000;
    }
    REP(i, 2) {
        if (v[i] == 1) {
            ans += 300000;
        } else if (v[i] == 2) {
            ans += 200000;
        } else if (v[i] == 3) {
            ans += 100000;
        }
    }
    cout << ans << endl;
    return 0;
}
