#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

// in
// 6 3
// 4 3 1 0 9 8
// out
// 18

int main() {
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    ll ans = 0;
    for (ll i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            ans += a[i] + a[i + 1] - x;
            a[i + 1] -= min(a[i + 1], (a[i] + a[i + 1] - x));
        }

        // repv(a) cout << *it << " ";
        // cout << endl;
    }
    cout << ans << endl;

    return 0;
}
