#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{

    ll l, r;
    cin >> l >> r;  

    ll mi = 2019;
    for (ll i = l; i < l + 2019; i++) {
        for (ll j = i + 1; j <= min(r, i + 2020); j++) {
            mi = min(mi, ((i % 2019) * (j % 2019)) % 2019);
        }
    }
    
    put(mi)

    return 0;
}