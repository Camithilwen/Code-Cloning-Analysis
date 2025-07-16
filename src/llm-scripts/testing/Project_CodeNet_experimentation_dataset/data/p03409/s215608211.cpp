#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N), b(N), c(N), d(N);
    vector<pair<ll, ll>> red, blue;
    vector<bool> isUsed(N, false);
    REP(i, N)
    {
        cin >> a[i] >> b[i];
        red.push_back(make_pair(a[i], b[i]));
    }
    REP(i, N)
    {
        cin >> c[i] >> d[i];
        blue.push_back(make_pair(c[i], d[i]));
    }
    sort(ALL(blue));

    ll ans = 0;
    REPV(it, blue)
    {
        ll bx = it->first, by = it->second;
        priority_queue<pair<ll, ll>> q;
        REP(i, N)
        {
            if (!isUsed[i])
            {
                ll rx = red[i].first, ry = red[i].second;
                if (rx < bx && ry < by)
                {
                    q.push(make_pair(ry, i));
                }
            }
        }
        if (!q.empty())
        {
            ans++;
            ll maxIndex = q.top().second;
            isUsed[maxIndex] = true;
        }
    }

    cout << ans << endl;
}
