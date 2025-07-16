#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ll long long
#define lld long double
#define ALL(x) x.begin(), x.end()
using namespace std;

const double EPS = 1e-3;
const double PI = 3.1415926535897932384626433832795028841971;
const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, int>> x(n), y(n);
    rep(i, n)
    {
        x[i].second = i;
        cin >> x[i].first;
        y[i].second = i;
        cin >> y[i].first;
    }
    sort(ALL(x));
    sort(ALL(y));
    vector<int> xpos(n), ypos(n);
    rep(i, n)
    {
        xpos[x[i].second] = i;
        ypos[y[i].second] = i;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;
    pque.push({0, 0});
    ll ans = 0;
    vector<bool> used(n, false);
    while (!pque.empty())
    {
        //       cerr << pque.size() << endl;
        ll cost = pque.top().first;
        int idx = pque.top().second;
        pque.pop();
        if (used[idx])
        {
            continue;
        }
        //cerr << idx << " " << cost << endl;
        used[idx] = true;
        //cerr << xpos[idx] << endl;
        ans += cost;
        if (xpos[idx] > 0 && !used[x[xpos[idx] - 1].second])
        {
            pque.push({llabs(x[xpos[idx]].first - x[xpos[idx] - 1].first), x[xpos[idx] - 1].second});
        }
        if (ypos[idx] > 0 && !used[y[ypos[idx] - 1].second])
        {
            pque.push({llabs(y[ypos[idx]].first - y[ypos[idx] - 1].first), y[ypos[idx] - 1].second});
        }

        if (xpos[idx] + 1 < n && !used[x[xpos[idx] + 1].second])
        {
            pque.push({llabs(x[xpos[idx]].first - x[xpos[idx] + 1].first), x[xpos[idx] + 1].second});
        }
        if (ypos[idx] + 1 < n && !used[y[ypos[idx] + 1].second])
        {
            pque.push({llabs(y[ypos[idx]].first - y[ypos[idx] + 1].first), y[ypos[idx] + 1].second});
        }
    }
    cout << ans << endl;

    return 0;
}