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
    const ll d[2][2] = {{0, 1}, {1, 0}};
    const ll MAXV = 80 * (80 + 80);
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];
    vector<vector<vector<bool>>> dp(h, vector<vector<bool>>(w, vector<bool>(MAXV + 1, false)));
    dp[0][0][abs(a[0][0] - b[0][0])] = true;
    queue<pair<ll, ll>> q;
    q.push(make_pair(0, 0));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    seen[0][0] = true;
    while(!q.empty()) {
        pair<ll, ll> p = q.front(); q.pop();
        ll x = p.second, y = p.first;
        rep(i, 2) {
            ll nx = x + d[i][1];
            ll ny = y + d[i][0];
            if ((nx >= w) || (ny >= h)) continue;
            rep(j, MAXV + 1) {
                if (!dp[y][x][j]) continue;
                dp[ny][nx][j + abs(a[ny][nx] - b[ny][nx])] = true;
                dp[ny][nx][abs(j - abs(a[ny][nx] - b[ny][nx]))] = true;
            }
            if (!seen[ny][nx]) {
                seen[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    rep(i, MAXV + 1) {
        if (dp[h - 1][w - 1][i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
