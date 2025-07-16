#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
const int mod = 1000000007;

vector<ll> divisor(ll n) {
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i != n) {
                res.push_back(n / i);
            }
        }
    }
    sort(begin(res), end(res));
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

bool isPrime(ll x) {
    ll i;
    if(x < 2)
        return 0;
    else if(x == 2)
        return 1;
    if(x % 2 == 0)
        return 0;
    for(i = 3; i * i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}

int main() {
    ll A, B;
    cin >> A >> B;

    ll ab_gcd = gcd(A, B);
    vector<ll> ab_divisor;
    ab_divisor = divisor(ab_gcd);

    ll cnt = 1;
    for(ll i = 0; i < ab_divisor.size(); i++) {
        if(isPrime(ab_divisor[i])) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}