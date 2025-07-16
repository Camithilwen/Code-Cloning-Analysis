#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5, mod = 1e9 + 7;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int n, m, c = 0, x;
    map<int, ll> mp;
    mp[0]++;
    cin >> n >> m;
    while (n--)
        cin >> x,
        c += x,
        c %= m,
        mp[c]++;
    ll ans = 0;
    for (auto it: mp)
        ans += it.second * (it.second - 1) / 2;
    cout << ans;
    return 0;
}