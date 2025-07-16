#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

std::map<long long, int> primeFact(long long n) {
    std::map<long long, int> res;
    for (long long i=2; i*i<=n; i++) {
        while (n%i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        res[n] = 1;
    }
    return res;
}

long long inv(long long n) {
    long long res = 1;
    while (n > 1) {
        res *= (MOD - MOD/n);
        res %= MOD;
        n = MOD % n;
    }
    return res;
}

void solve() {
    int n;
    ll m;
    cin >> n >> m;

    auto pf = primeFact(m);

    vector<ll> comb(31);
    ll nume = 1, deno = 1;
    for (int i=0; i<31; ++i) {
        comb.at(i) = nume * inv(deno) % MOD;
        nume *= n+i;
        nume %= MOD;
        deno *= i+1;
        deno %= MOD;
    }

    ll res = 1;
    for (auto iter=pf.begin(); iter!=pf.end(); ++iter) {
        res *= comb.at(iter->second);
        res %= MOD;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
