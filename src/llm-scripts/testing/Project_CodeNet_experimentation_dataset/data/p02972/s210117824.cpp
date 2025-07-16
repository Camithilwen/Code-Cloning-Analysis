#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll> > fac(n+1, vector<ll>());
    for (int i = 1; i <= n; i++) {
        // fac[i]にiの約数を入れる
        for (int j = 1; i * j <= n; j++) {
            fac[i * j].push_back(i);
        }
    }

    vector<ll> c(n + 1);
    vector<ll> res;
    for (int i = n; i >= 1; i--) {
        int ai = a[i - 1];
        if (ai != c[i] % 2) {
            res.push_back(i);
            for (int f: fac[i]) {
                c[f]++;
            }
        }
    }

    if (res.size() <= 0) {
        put(0);
        return;
    }

    reverse(all(res));
    put(res.size());
    rep(i, res.size()) cout << res[i] << (i == res.size() - 1 ? "" : " ");
    cout << endl;
}
signed main(){ Main();return 0;}