// https://atcoder.jp/contests/abc134/tasks/abc134_d
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
    bitset<200001> bs;
    FOR(i, 1, N + 1) {
        int t;
        cin >> t;
        if (t) {
            bs.set(i);
        }
    }
    bitset<200001> ans;
    int cnt = 0;
    for (int i = N; i >= 1; i--) {
        int sum = 0;
        for (int j = i * 2; j <= N; j += i) {
            sum += ans[j];
        }
        if (sum % 2 != bs[i]) {
            ans.set(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= N; i++) {
        if (ans[i]) {
            cout << i << (--cnt ? " " : "\n");
        }
    }

    return 0;
}
