#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define ALL(x) x.begin(), x.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;
using lld = long double;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
using PII = pair<int, int>;
random_device rnd;
mt19937 mt(rnd());

const int IINF = 1 << 30;
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    VVI v(n, VI(m));
    rep(i, n) rep(j, m)
    {
        cin >> v[i][j];
        v[i][j]--;
    }
    VI p(n, 0);
    int ans = IINF;
    map<int, bool> used;
    rep(j, m)
    {
        map<int, int> mp;
        rep(i, n)
        {
            mp[v[i][p[i]]]++;
        }
        int delid = -1;
        int delnum = 0;
        rep(i, m)
        {
            if (mp[i] > delnum)
            {
                delnum = mp[i];
                delid = i;
            }
        }
        chmin(ans, delnum);
        used[delid] = true;
        if (j == m - 1)
            break;
        rep(i, n)
        {
            while (used[v[i][p[i]]])
                p[i]++;
        }
    }
    cout << ans << endl;
    return 0;
}