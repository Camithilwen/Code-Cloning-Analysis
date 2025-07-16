#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout << ((f) ? "Yes" : "No") << endl;
#define YORN(f) cout << ((f) ? "YES" : "NO") << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(x) cout << x << endl;
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll sum = 0;
    rep(j, n)
    {
        ll i = j + 1;
        if (i % 15 == 0)
        {
        }
        else if (i % 3 == 0)
        {
        }
        else if (i % 5 == 0)
        {
        }
        else
        {
            sum += i;
        }
    }
    put(sum)
    return 0;
}