#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    vector<ll> acum(n+1, 0);
    rep(i, n) {
        acum[i+1] = acum[i] + a[i];
    }

    int l = 1;
    int r = 3;
    ll ans = LINF;
    for (int i = 2; i < n-1; i++) {
        if (r <= i) r = i+1;
        while (l+1 < i && abs(acum[l+1] - (acum[i] - acum[l+1])) <= abs(acum[l] - (acum[i] - acum[l]))) {
            l++;
        }
        while (r+1 < n && abs(acum[r+1] - acum[i] - (acum[n] - acum[r+1])) <= abs(acum[r] - acum[i] - (acum[n] - acum[r]))) {
            r++;
        }
        ll mn = min({acum[l], (acum[i] - acum[l]), acum[r] - acum[i], acum[n] - acum[r]});
        ll mx = max({acum[l], (acum[i] - acum[l]), acum[r] - acum[i], acum[n] - acum[r]});
        ans = min(ans, mx-mn);
    }

    cout << ans << endl;




    return 0;
}