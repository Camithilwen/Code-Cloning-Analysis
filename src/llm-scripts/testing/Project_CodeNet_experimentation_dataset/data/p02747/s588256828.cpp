#include <bits/stdc++.h>
#include <gmpxx.h>

#define NREP() for(ll i = 0; i < n; i++)
#define MREP() for(ll j = 0; j < m; j++)
#define REP(i, x, y) for(ll i = x; i < y; i++)
#define ALL(x) (x).begin(), (x).end()
#define MSG(x) cout << x << endl;
#define MSGF(x, n) MSG(fixed << setprecision(n) << x)
#define END(x) cout << x << endl; return(0);
#define IPT(v, n) REP(i, 0, n){ cin >> v[i]; }
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

const static ll MOD = 1e9 + 7;
const static ll INF = 1LL << 30;

ll a, b, c, d, k, l, m, n, h, w, q, x, y;
string s, t;

ll ans = 0;
ll sum = 0;
ll cnt = 0;
ll cur = 0;
ll tmp = 0;
ll mini = INF;
ll maxi = 0;

double ave = 0.0;

ll mod_pow(ll base, ll power) {
    if (power == 0) return 1;
    if (power == 1) return base % MOD;
    if (power % 2 == 0) return ((mod_pow(base % MOD, (power / 2)) % MOD) * (mod_pow(base, (power / 2)) % MOD)) % MOD;
    return (base % MOD * (mod_pow(base % MOD, power - 1) % MOD)) % MOD;
}

ll mod_fact(ll number) {
    ll ret = 1;
    ll count = 1;
    while (count <= number) {
        ret *= (count % MOD);
        ret %= MOD;
        count++;
    }
    return ret % MOD;
}

ll gcd(ll a, ll b) {
    if (a < b) {
        return gcd(b, a);
    }
    ll c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    cin >> s;
    if (s.size() % 2 != 0) {
        END("No")
    }

    REP(i, 0, s.size()) {
        if (i % 2 == 0) {
            if (s.at(i) != 'h') {
                END("No")
            }
        } else {
            if (s.at(i) != 'i') {
                END("No")
            }
        }
    }
    MSG("Yes")
}
