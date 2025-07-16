#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)

int n, k;
ll ans = 10000000000, len;
int main()
{
    cin >> n >> k;
    vector<ll> x(n);
    rep(i, 0, n)
    {
        cin >> x[i];
    }

    ll l, r, lr, rl;
    for (int i = 0; i <= (n - k); i++)
    {
        l = i;
        r = l + k - 1;
        rl = abs(x[r]) + abs(x[r] - x[l]);
        lr = abs(x[l]) + abs(x[r] - x[l]);
        len = min(lr, rl);
        // cout << ans << "," << len << endl;
        ans = min(ans, len);
    }

    cout << ans << endl;
    return 0;
}
