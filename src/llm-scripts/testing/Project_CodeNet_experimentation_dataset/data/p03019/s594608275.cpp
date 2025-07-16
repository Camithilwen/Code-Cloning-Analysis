#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> b(n);
    vector<ll> l(n);
    vector<ll> u(n);
    vector<ll> score(n);
    ll ascore = 0;
    ll bsum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> b[i] >> l[i] >> u[i];
        score[i] = l[i] * b[i] + (u[i] * (x-b[i]));
        ascore += b[i] * l[i];
        bsum += b[i];
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int lhs, int rhs)
    {
        return score[lhs] > score[rhs];
    });
    vector<ll> sum(n+1);
    for(int i = 0; i < n; i++) sum[i+1] = sum[i] + score[ord[i]];
    ll h = bsum;
    ll le = -1;
    while(h - le > 1)
    {
        ll mid = (h + le) >> 1;
        ll num = mid / x;
        ll y = mid % x;
        ll tmax = 0;
        for(int i = 0; i < n; i++)
        {
            ll tmp;
            if(num > i) tmp = sum[num+1] - score[ord[i]];
            else tmp = sum[num];
            int nn = ord[i];
            if(y > b[nn]) tmp += b[nn] * l[nn] + (y - b[nn]) * u[nn];
            else tmp += y * l[nn];
            tmax = max(tmax, tmp);
        }
        if(tmax - ascore >= 0)
        {
            h = mid;
        }
        else
        {
            le = mid;
        }
    }
    cout << h << endl;
}
