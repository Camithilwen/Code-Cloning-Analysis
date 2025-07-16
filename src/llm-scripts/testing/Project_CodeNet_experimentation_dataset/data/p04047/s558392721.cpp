#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

const ll maxn = 1e3 + 10;

ll a[maxn];

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n , res = 0;
	cin >> n;

	for (ll i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1 , a + 2 * n + 1);

    for (ll i = 1; i <= n; i++)
    {
        res += a[2 * i - 1];
    }

    cout << res;
}
