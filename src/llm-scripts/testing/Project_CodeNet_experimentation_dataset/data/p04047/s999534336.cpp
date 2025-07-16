#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

void solve(void)
{
    ll n;
    cin >> n;
    n *= 2;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        ans += min(v[i], v[i + 1]);
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}