#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n, T;
    cin >> n >> T;
    int t[n];
    rep(i, n) {
        cin >> t[i];
    }
    ll ans = 0;
    rep(i, n) {
        if (i+1 < n) {
            ans += min(T, t[i+1] - t[i]);
        } else {
            ans += T;
        }
    }
    cout << ans << endl;
}
