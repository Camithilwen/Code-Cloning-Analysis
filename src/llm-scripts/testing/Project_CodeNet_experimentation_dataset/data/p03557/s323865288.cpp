// https://atcoder.jp/contests/abc077/tasks/arc084_a
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
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    int ans = 0;
    for (auto &x : B) {
        // 配列Aからxより小さい値を探す
        auto ia = lower_bound(ALL(A), x);
        int a = ia - A.begin();
        // 配列Cからxより大きい値を探す
        auto ic = lower_bound(ALL(C), x + 1);
        int c = C.end() - ic;
        ans += a * c;
    }
    cout << ans << endl;

    return 0;
}
