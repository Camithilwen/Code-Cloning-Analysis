#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    rep(i, 0, n) {
        if (a[i] != b[i] && b[i] != c[i] && c[i] != a[i]) ans += 2;
        else if (a[i] == b[i] && b[i] == c[i]) continue;
        else ans++;
    }

    cout << ans << endl;
    return 0;
}
