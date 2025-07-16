#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<ll> f(ll n) {
    vector<ll> res;
    for (ll a = 2; a*a <= n; a++) {
        if (n%a != 0) continue;
        while (n%a == 0) {
            n /= a;
        }
        res.push_back(a);
    }
    if (n != 1) res.push_back(n);
    return res;
} 

int main() {
    ll a, b;
    cin >> a >> b;
    auto ares = f(a);
    auto bres = f(b);
    int ans = 0;
    for (auto x : ares) {
        for (auto y : bres) {
            if (x == y) ans++;
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}