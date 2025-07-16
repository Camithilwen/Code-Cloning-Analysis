#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n, x, a[200];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> x;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    ll dp[209][100009];
    rep(i, 100009) dp[0][i] = i;
    rep(i, n) rep(j, 100009) dp[i + 1][j] =
        (dp[i][j % a[i]] + i * dp[i][j]) % mod;
    cout << dp[n][x] << endl;
}