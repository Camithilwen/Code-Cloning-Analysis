#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (int)(n - 1); i > -1; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];
    reverse(p.begin(), p.end());
    reverse(c.begin(), c.end());
    int ans = 1e9;
    rep(bit, 1 << d)
    {
        int score = 0, cnt = 0;
        rep(i, d)
        {
            if (bit & (1 << i))
            {
                bool ok = true;
                rep(j, p[i])
                {
                    score += (d - i) * 100;
                    cnt++;
                    if (score >= g)
                    {
                        ok = false;
                        ans = min(ans, cnt);
                        break;
                    }
                }
                if (ok)
                {
                    score += c[i];
                    if (score >= g)
                    {
                        ans = min(ans, cnt);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}