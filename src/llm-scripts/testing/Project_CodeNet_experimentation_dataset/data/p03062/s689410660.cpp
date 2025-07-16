#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    bool is_minus_even = true;
    bool is_zero_exist = false;
    rep(i, n)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            is_minus_even = !is_minus_even;
        }
        if (a[i] == 0)
        {
            is_zero_exist = true;
        }
    }
    ll ans = 0;
    if (is_minus_even == true || (!is_minus_even && is_zero_exist))
    {
        rep(i, n)
        {
            ans += abs(a[i]);
        }
    }
    else
    {
        rep(i, n)
        {
            a[i] = abs(a[i]);
        }
        sort(all(a));
        ans = accumulate(a.begin() + 1, a.end(), 0LL) - a[0];
    }
    cout << ans << endl;
    return 0;
}