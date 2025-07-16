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
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll pow2 = 1;
    ll sum = 0;
    ll mod = 7LL + 1e9;
    rep(_i, 61) {
        ll one = 0, zero = 0;
        rep(i, n) {
            ll v = A[i] % 2;
            if (v == 1) one++;
            else zero++;
            A[i] /= 2;
        }

        sum += (one * zero % mod) * pow2 % mod;
        sum %= mod;

        pow2 *= 2;
        pow2 %= mod;
    }

    put(sum);
}
signed main(){ Main();return 0;}