#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n), r(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        r[b].push_back(a);
    }
    vector<ll> ans(n + 1);
    rep(i, n) {
        queue<ll> q;
        vector<ll> dist(n, LONG_LONG_MAX);
        vector<ll> prev(n, LONG_LONG_MAX);
        q.push(i);
        dist[i] = 0;
        while(!q.empty()) {
            ll now = q.front(); q.pop();
            rep(ii, sz(g[now])) {
                ll next = g[now][ii];
                if (dist[next] <= (dist[now] + 1)) continue;
                dist[next] = dist[now] + 1;
                prev[next] = now;
                q.push(next);
            }
        }
        vector<ll> tmp;
        q.push(i);
        tmp.push_back(i);
        while(!q.empty()) {
            ll now = q.front(); q.pop();
            ll mi = -1, mv = LONG_LONG_MAX;
            rep(ii, sz(r[now])) {
                ll next = r[now][ii];
                if (mv <= dist[next]) continue;
                mv = dist[next];
                mi = next;
            }
            if ((mv == LONG_LONG_MAX) || (mi == i)) break;
            tmp.push_back(mi);
            q.push(mi);
        }
        if ((sz(tmp) == 1) || (sz(tmp) >= sz(ans))) continue;
        reverse(tmp.begin() + 1, tmp.end());
        ans = tmp;
    }
    if (sz(ans) == (n + 1)) {
        cout << -1 << endl;
    }
    else {
        cout << sz(ans) << endl;
        rep(i, sz(ans)) cout << (ans[i] + 1) << endl;
    }
    return 0;
}
