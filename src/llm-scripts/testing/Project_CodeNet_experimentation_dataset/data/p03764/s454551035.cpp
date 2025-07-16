#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;
void add(ll &a, ll b)
{
    a = (a + b) % MOD;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(m);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    ll xsum = 0;
    ll ex = 0;
    for(int i = 1; i < n; i++)
    {
        ll cand = x[i] - x[i-1];
        add(ex, i * cand);
        add(xsum, ex);
    }
    ll ysum = 0;
    ll ey = 0;
    for(int i = 1; i < m; i++)
    {
        ll cand = y[i] - y[i-1];
        add(ey, i * cand);
        add(ysum, ey);
    }

    cout << xsum * ysum % MOD << endl;
}
