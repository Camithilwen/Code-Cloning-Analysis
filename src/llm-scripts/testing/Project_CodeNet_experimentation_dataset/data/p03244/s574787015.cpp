#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int ans, n, m1, m2, m3, m4;
int a[N];
int cnt0[N];
int cnt1[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i += 2) {
        int m = a[i];
        ++cnt0[m];
        if (m == m1) continue;
        if (cnt0[m] > cnt0[m1]) {
            m2 = m1;
            m1 = m;
        } else if (cnt0[m] > cnt0[m2]) {
            m2 = m;
        }
    }
    for (int i = 1; i < n; i += 2) {
        int m = a[i];
        ++cnt1[m];
        if (m == m3) continue;
        if (cnt1[m] > cnt1[m3]) {
            m4 = m3;
            m3 = m;
        } else if (cnt1[m] > cnt1[m4]) {
            m4 = m;
        }
    }
    if (m2 == m1) m2 = 0;
    if (m4 == m3) m4 = 0;
    if (m1 != m3) {
        ans = n - cnt0[m1] - cnt1[m3];
    } else {
        ans = min(n - cnt0[m1] - cnt1[m4],
                  n - cnt0[m2] - cnt1[m3]);
    }
    cout << ans << endl;
    return 0;
}
