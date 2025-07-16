#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

ll keta(ll a, ll b)
{
    int cnt_a = 0, cnt_b = 0;
    while (a)
    {
        cnt_a++;
        a /= 10;
    }
    while (b)
    {
        cnt_b++;
        b /= 10;
    }
    ll ans = max(cnt_a, cnt_b);
    return ans;
}

int main()
{

    ll n;
    cin >> n;

    ll ans = 1001001001;
    for (ll a = 1; a * a <= n; a++)
    {
        if (n % a)
        {
            continue;
        }
        ll b = n / a;
        ans = min(ans, keta(a, b));
    }

    cout << ans << '\n';
    return (0);
}
