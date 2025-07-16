#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
#pragma region Debug
istream &operator>>(istream &is, P &a)
{
    return is >> a.first >> a.second;
}
ostream &operator<<(ostream &os, const P &a) { return os << "(" << a.first << "," << a.second << ")"; }

template <typename T>

void view(const std::vector<T> &v)
{
#ifndef ONLINE_JUDGE
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
#endif
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv)
{
    for (const auto &v : vv)
    {
        view(v);
    }
}
#pragma endregion

int main()
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll neg;
    ll ans = 0;
    rep(i, n)
    {
        if (a[i] <= 0)
        {
            neg.emplace_back(abs(a[i]));
        }
        ans += abs(a[i]);
    }
    int k = neg.size();

    if (k % 2)
    {
        ll sml = 10000000000;
        rep(i, n) sml = min(sml, abs(a[i]));
        ans -= sml * 2;
    }
    cout << ans << endl;

    return 0;
}