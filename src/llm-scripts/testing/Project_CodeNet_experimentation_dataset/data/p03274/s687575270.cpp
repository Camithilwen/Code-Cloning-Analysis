#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, m, k;
int a[N];
ll ans;

int main() {
    cin >> n >> k;
    m = n;
    ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (m == n && a[i] >= 0) {
            m = i;
        }
    }
    for (int i = 0; i <= min(k, m); ++i) {
        if (m + k - i - 1 >= n) continue;
        ll lv = 0;
        ll rv = 0;
        if (i)
            lv = -a[m - i];
        if (k - i)
            rv = a[m + k - i - 1];
        // cout << i << ' ' << lv << ' ' << rv << endl;
        ans = min(ans, min(lv, rv) * 2 + max(lv, rv));
    }
    cout << ans << endl;
    return 0;
}
