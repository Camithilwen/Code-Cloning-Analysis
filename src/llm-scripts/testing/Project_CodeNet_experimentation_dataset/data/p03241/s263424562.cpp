#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;

    set<ll> div;
    for (int i = 1; i * i < m; i++) {
        if (m % i == 0) {
            div.insert(i);
            div.insert(m / i);
        }
    }

    ll ans = 1;
    for (auto iter = div.begin(); iter != div.end(); iter++) {
        if (m / (*iter) >= n) {
            ans = (*iter);
        }
    }
    cout << ans << endl;

    return 0;
}

