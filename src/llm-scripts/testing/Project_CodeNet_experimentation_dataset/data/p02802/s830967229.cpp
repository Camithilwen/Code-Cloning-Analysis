#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vt<int> p(n + 1), ac(n + 1);
    while (m--) {
        int x;
        string s;
        cin >> x >> s;
        if (s == "AC") ac[x] = 1;
        else if (!ac[x]) p[x]++;
    }

    int pen = 0;
    for (int i = 1; i <= n; i++) pen += p[i] * ac[i];
    cout << accumulate(all(ac), 0) << ' ' << pen;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
