#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define scl(n) scanf("%lld", &n)
#define pcl(n) printf("%lld\n", n)
#define pcl1(n) printf("%lld ", n)
#define nln printf("\n")
#define dev(x) cout << #x << " " << x << " ";
#define PTT pair<ll, ll>

map<ll, ll> mp, mp1;
map<ll, ll>::iterator itr;

int main()
{
    ll t, n, x;
    scl(n);
    ll mn = 1e10, d;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d = max(i, n / i);
            ll cnt = 0;
            while (d >= 1)
            {
                d /= 10;
                cnt++;
            }
            mn = min(cnt, mn);
        }
    }
    pcl(mn);
    return 0;
}