#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using vint = vector<int>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
using vp = vector<P>;
using vpp = vector<pair<P, P>>;
using vvp = vector<vp>;

#define rep(i, n) for (int i = 0; i < n; ++i)

P bounds = P(0, 0);
void rot(vp *up, vp *down, vp *left, vp *right)
{
    vector<vp *> vecs = {up, down, left, right};
    rep(i, 4)
    {
        vp *a = vecs[i];
        rep(j, (*a).size())
        {
            P now = (*a)[j];
            (*a)[j] = P(now.second, -now.first + bounds.first);
        }
    }
    swap(bounds.first, bounds.second);
    swap(*down, *left);
    swap(*down, *up);
    swap(*down, *right);
}

bool comp(P l, P r)
{
    return (l.first + l.second) < (r.first + r.second);
}

const ll INF = 1e10 + 5;

int main()
{
    int n;
    cin >> n;
    vp up, down, left, right;
    rep(i, n)
    {
        int x, y;
        char u;
        cin >> x >> y >> u;
        P p = P(x, y);
        if (p.first > bounds.first)
        {
            bounds = P(p.first, bounds.second);
        }
        if (p.second > bounds.second)
        {
            bounds = P(bounds.first, p.second);
        }
        if (u == 'U')
        {
            up.emplace_back(p);
        }
        else if (u == 'D')
        {
            down.emplace_back(p);
        }
        else if (u == 'R')
        {
            right.emplace_back(p);
        }
        else if (u == 'L')
        {
            left.emplace_back(p);
        }
    }

    ll ans = INF;
    rep(i, 4)
    {

        map<int, vp> m;
        for (P p : up)
        {
            int sum = p.first + p.second;
            m[sum].emplace_back(P(p.second, 0));
        }
        for (P p : right)
        {
            int sum = p.first + p.second;
            m[sum].emplace_back(P(p.second, 1));
        }
        for (auto x : m)
        {
            vp b = x.second;
            sort(b.begin(), b.end());
            rep(j, b.size() - 1)
            {
                if (!b[j].second && b[j + 1].second)
                {
                    // collision between up and right
                    // not b[j].second && !b[j].second because we sorted by Y coords
                    ll now = b[j + 1].first - b[j].first;
                    now *= 10;
                    ans = min(ans, now);
                    break;
                }
            }
        }

        map<int, vp> q;
        for (P p : up)
        {
            q[p.first].emplace_back(P(p.second, 0));
        }
        for (P p : down)
        {
            q[p.first].emplace_back(P(p.second, 1));
        }
        for (auto x : q)
        {
            vp b = x.second;
            sort(b.begin(), b.end());
            rep(j, b.size() - 1)
            {
                if (!b[j].second && b[j + 1].second)
                {
                    ll now = b[j + 1].first - b[j].first;
                    now *= 5;
                    ans = min(ans, now);
                    break;
                }
            }
        }

        rot(&up, &down, &left, &right);
    }

    if (ans == INF)
    {
        cout << "SAFE" << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}