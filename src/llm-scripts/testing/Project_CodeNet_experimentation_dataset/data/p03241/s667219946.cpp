#include <algorithm>
#include <cmath>
#include <deque>
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
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
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
    ll N, M;
    cin >> N >> M;

    vector<ll> divs = divisor(M);
    ll ans = 0;
    for (ll i = divs.size() - 1; i >= 0; i--) {
        if (M % divs[i] == 0) {
            ll sub_m = M / divs[i];
            if (sub_m >= N) {
                ans = max(ans, divs[i]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
