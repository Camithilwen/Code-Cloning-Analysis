#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 30)
#define EPS 1e-10
#define MOD 1000000007

#define rep(i, n) FOR(i, 0, n)
#define FOR(i, x, n) for (int i = (x); i < (n); ++i)
#define all(v) (v).begin(), (v).end()

using ll = long long;

template<class T> void chmax(T& a, T b){ if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b){ if (a > b) { a = b; } }

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    cout << (n + x - 1) / x * t << endl;

    return 0;
}