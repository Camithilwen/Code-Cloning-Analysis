#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p, a, b) for (ll p = a; p < b; p++)
#define F first
#define S second
using namespace std;

typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;

int main()
{
    ll t, i, j, k, ans, n, m, sum = 0, x;

    //cin>>t;
    t = 1;
    while (t--)
    {
        cin >> n >> m;
        string s;
        vll wa(n + 1), ac(n + 1);

        ll c1 = 0, c2 = 0;
        rep(p, 0, m)
        {
            cin >> x >> s;
            if (s == "WA")
                wa[x]++;
            else
            {
                if (ac[x] == 0)
                {
                    c1++;
                    c2 += wa[x];
                    ac[x] = 1;
                }
            }
        }

        cout << c1 << " " << c2;
    }

    return 0;
}
