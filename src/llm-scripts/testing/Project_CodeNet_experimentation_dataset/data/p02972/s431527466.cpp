#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

// 約数の列挙 O(√n)
vector<ll> divisor(ll n) {
    vector<ll> res;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }

    return res;
}

int main() {
    INIT;

    ll N;
    cin >> N;
    vector<ll> a(N + 1, 0);
    reps(i, 1, N + 1) cin >> a[i];

    vector<ll> b;
    vector<ll> sum(N + 1, 0);
    ll ans = 0;

    for (ll i = N; i > 0; i--) {
        if (sum[i] % 2 != a[i]) {
            b.pb(i);
            vector<ll> divs = divisor(i);
            rep(j, SZ(divs)) { sum[divs[j]]++; }
        }

        // cout << i << ": ";
        // repv(sum) cout << *it << " ";
        // cout << endl;
    }

    sort(ALL(b));
    cout << SZ(b) << endl;
    if (SZ(b) > 0) {
        repv(b) { cout << *it << " "; }
        cout << endl;
    }

    return 0;
}