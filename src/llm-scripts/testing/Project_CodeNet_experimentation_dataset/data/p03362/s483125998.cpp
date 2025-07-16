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

// Eratosthenes
vector<int> eratTable;

vector<ll> eratosthenes(ll n) {
    eratTable.assign(n + 1, 1);
    eratTable[0] = 0;
    eratTable[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (eratTable[i] == 1) {
            for (ll j = 2; i * j <= n; j++) {
                eratTable[i * j] = 0;
            }
        }
    }

    vector<ll> primes;
    rep(i, eratTable.size()) {
        if (eratTable[i] >= 1) {
            primes.push_back(i);
        }
    }

    return primes;
}

bool check(const vector<ll>& a) {
    for (ll i = 0; i < a.size() - 4; i++) {
        for (ll j = i + 1; j < a.size() - 3; j++) {
            for (ll k = j + 1; k < a.size() - 2; k++) {
                for (ll l = k + 1; l < a.size() - 1; l++) {
                    for (ll m = l + 1; m < a.size(); m++) {
                        ll v = a[i] + a[j] + a[k] + a[l] + a[m];
                        // 1なら素数
                        if (eratTable[v] == 1) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void Main()
{
    ll n;
    cin >> n;

    vector<ll> res;

    auto primes = eratosthenes(55555);

    rep (i, primes.size()) {
        if (primes[i] % 5 == 1) {
            res.push_back(primes[i]);
        }
    }

    rep(i, n) cout << res[i] << (i == n - 1 ? "" : " ");
    cout << endl;
}

signed main(){ Main();return 0;}