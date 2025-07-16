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

vector <ll> o;
vector <ll> e;
vector <ll> a;
vector <ll> b;

void print()
{
    for (ll i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << b.size() << endl;
    for (ll i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n , m;
	cin >> n >> m;

	for (ll i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;

        if (x & 1)
        {
            o.pb(x);
        }
        else
        {
            e.pb(x);
        }
    }

    if (o.size() == 0)
    {
        b.pb(1);
        for (ll i = 0; i < (ll)(e.size()) - 1; i++)
        {
            a.pb(e[i]);
            b.pb(e[i]);
        }
        a.pb(e.back());
        b.pb(e.back() - 1);

        print();
        return 0;
    }

    if (o.size() == 1)
    {
        if (n == o[0])
        {
            a.pb(o[0]);
            if (o[0] > 1)
            {
                b.pb(o[0] - 1);
            }
            b.pb(1);
        }
        else
        {
            a.pb(o[0]);
            b.pb(o[0] + 1);
            for (ll i = 0; i < (ll)(e.size()) - 1; i++)
            {
                a.pb(e[i]);
                b.pb(e[i]);
            }
            a.pb(e.back());
            b.pb(e.back() - 1);
        }

        print();
        return 0;
    }

    if (o.size() == 2)
    {
        a.pb(o[0]);
        if (o[0] > 1)
        {
            b.pb(o[0] - 1);
        }

        for (ll i = 0; i < e.size(); i++)
        {
            a.pb(e[i]);
            b.pb(e[i]);
        }
        a.pb(o[1]);
        b.pb(o[1] + 1);

        print();
        return 0;
    }

    cout << "Impossible";
    return 0;
}
