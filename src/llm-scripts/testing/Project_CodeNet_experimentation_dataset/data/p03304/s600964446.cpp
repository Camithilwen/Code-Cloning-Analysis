#include <bits/stdc++.h>
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define repr(i, n, m) for (int i = (int)(n) - 1; i >= (int)(m); i--)
using namespace std;
using ll = int64_t;
const int MOD = 1000000007; // 10^9+7

int main() {
    double n, m, d;
    cin >> n >> m >> d;

    double ans;
    if (d == 0) {
        ans = (m - 1) / n;
    } else {
        ans = 2 * (n - d) * (m - 1) / (n * n);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
