#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int A, B, M;
    cin >> A >> B >> M;

    vector<int> a(A);
    REP(i, A) cin >> a[i];

    vector<int> b(B);
    REP(i, B) cin >> b[i];

    vector<int> x(M), y(M), c(M);
    REP(i, M) cin >> x[i] >> y[i] >> c[i];

    REP(i, M) {
        x[i]--;
        y[i]--;
    }

    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());

    int ans = minA + minB;
    REP(i, M) {
        ans = min(ans, a[x[i]] + b[y[i]] - c[i]);
    }

    cout << ans << '\n';
    return 0;
}