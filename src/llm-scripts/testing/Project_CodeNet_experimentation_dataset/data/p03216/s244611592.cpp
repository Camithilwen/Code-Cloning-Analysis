#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, q;
    string s;
    cin >> n >> s >> q;
    for (ll i = 0; i < q; i++)
    {
        ll k;
        ll d, m, dm, dmc;
        d = m = dm = dmc = 0;
        scanf("%d", &k);
        for (ll i = 0; i < n; i++)
        {
            if (i - k >= 0)
            {
                if (s[i - k] == 'D')
                {
                    d--;
                    dm -= m;
                }
                if (s[i - k] == 'M')
                    m--;
            }
            if (s[i] == 'D')
                d++;
            if (s[i] == 'M')
            {
                m++;
                dm += d;
            }
            if (s[i] == 'C')
                dmc += dm;
        }
        cout << dmc << endl;
    }
}