#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;
void solve(void)
{
    int n;
    cin >> n;
    vector<int> a(n + 2);
    rep(i, n) cin >> a[i + 1];
    a[0] = 0, a[n + 1] = 0;
    int res = 0;
    rep(i, n + 1) res += abs(a[i] - a[i + 1]);
    rep(i, n)
    {
        int x = abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]);
        int y = abs(a[i] - a[i + 2]);
        cout << res - x + y << endl;
    }
}
int main(void)
{
    solve();
}
