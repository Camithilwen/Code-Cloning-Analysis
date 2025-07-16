#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, k) {
        vector<ll> b(n + 1, 0);
        rep(j, n) {
            ll l = max(0LL, j - a[j]);
            ll r = min(n, j + a[j] + 1);
            b[l]++;
            b[r]--;
        }
        ll cnt = 0;
        rep(j, n) {
            b[j + 1] += b[j];
            a[j] = b[j];
            if (a[j] == n) cnt++;
        }
        if (cnt == n) break;
    }
    rep(i, n) printf("%lld%s", a[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
