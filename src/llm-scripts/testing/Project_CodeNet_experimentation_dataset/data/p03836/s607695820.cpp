#include <bits/stdc++.h>
using namespace std;
#define fio                         \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                    \
cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define pi pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define sz(x) (ll) x.size()
#define all(x) x.begin(), x.end()
#define time_passed 1.0 * clock() / CLOCKS_PER_SEC
ll MOD = 1e9 + 7;
ll MOD1 = 1e9 + 123;
ll MOD2 = 1e9 + 321;

int main()
{
    fio;
    ll t, a, n, q, k, i, l, m, c, u, f, j, p, r, x, y, s, b, d;
    ll sx, sy, tx, ty;
cin>>sx>>sy>>tx>>ty;
    for (i=0;i<tx-sx;i++)
        cout<<'R';

    for (i=0;i<ty-sy;i++)
        cout<<'U';
    for (i=0;i<tx-sx;i++)
        cout<<'L';

    for (i=0;i<ty-sy;i++)
        cout<<'D';
    cout<<'D';
    for (i=0;i<tx-sx+1;i++)
        cout<<'R';

    for (i=0;i<ty-sy+1;i++)
        cout<<'U';
    cout<<'L';
    cout<<'U';
    for (i=0;i<tx-sx+1;i++)
        cout<<'L';

    for (i=0;i<ty-sy+1;i++)
        cout<<'D';

    cout<<'R';

    return 0;
}
