#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    ll n, T;
    cin >> n >> T;
    ll ans = 0;
    vector<ll> t(n);

    rep(i, n)
    {
        cin >> t[i];
    }
    rep(i, n)
    {
        if (i + 1 >= n)
        {
            ans += T;
        }
        else if (t[i + 1] > t[i] + T)
        { //かぶっていなかったら
            ans += T;
        }
        else
        {
            ans += t[i + 1] - t[i];
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
