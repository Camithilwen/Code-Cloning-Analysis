#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(j, m) for (int j = 0; j <= (int)(m); j++)

int main()
{
    int d;
    ll g;
    vector<ll> p, c;
    cin >> d >> g;
    p.resize(d);
    c.resize(d);
    rep(i, d)
    {
        cin >> p[i] >> c[i];
    }
    ll res = 1 << 29;
    for (int bit = 0; bit < (1 << d); ++bit)
    {
        ll sum = 0;
        ll num = 0;

        rep(i, d)
        {
            if (bit & (1 << i))
            {
                sum += c[i] + p[i] * 100 * (i + 1);
                num += p[i];
            }
        }
        if (sum >= g)
        {
            res = min(res, num);
        }
        else
        {
            for (int i = d - 1; i >= 0; i--)
            {
                if (bit & (1 << i))
                {
                    continue;
                }
                rep(j, p[i])
                {
                    if (sum >= g)
                    {
                        break;
                    }
                    sum += 100 * (i+1);
                    num++;
                } 
            }
            res = min(res, num);
        }
    }
    cout << res << endl;
}