#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

vector<ll> calc_divisor(ll n) {
    vector<ll> res;
    for (ll i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            ll j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

ll N, M;

int main() {
    cin >> N >> M;
    vector<ll> v = calc_divisor(M);

    reverse(v.begin(), v.end());
    ll ans = 0;
    rep(i, v.size()) {
        // cout << v[i] << endl;
        if (M % v[i] == 0) {
            ll tmp = M / v[i];
            if (tmp >= N) {
                ans = v[i];
                break;
            }
        }
    }
    cout << ans << endl;
}