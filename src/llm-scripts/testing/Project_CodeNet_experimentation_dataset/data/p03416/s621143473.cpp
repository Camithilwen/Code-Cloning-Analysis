#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll num = a; num <= b; num++) {
        bool yes = true;
        string s;
        ll ins = num;
        while (ins) {
            s.push_back('0' + ins % 10);
            ins /= 10;
        }
        rep(i, (s.size() - 1) / 2 + 1) {
            if (s[i] != s[s.size() - 1 - i]) yes = false;
        }
        if (yes) ans++;
    }
    cout << ans << "\n";
    return 0;
}