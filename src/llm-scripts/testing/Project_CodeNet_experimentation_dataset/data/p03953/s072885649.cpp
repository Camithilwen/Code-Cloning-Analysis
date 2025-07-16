#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

const int MN = 100010;
using D = double;
int n, m;
ll k;
D x[MN], ans[MN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    V<int> pm(n - 1);
    iota(pm.begin(), pm.end(), 0);
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p; p--;
        swap(pm[p], pm[p - 1]);
    }

    auto gao = [&](const V<int> &a, const V<int> &b) {
        V<int> c(n - 1);
        for (int i = 0; i < n - 1; i++) {
            c[i] = a[b[i]];
        }
        return c;
    };

    V<int> r(n - 1);
    iota(r.begin(), r.end(), 0);
    while (k) {
        if (k & 1) r = gao(r, pm);
        pm = gao(pm, pm);
        k >>= 1;
    }

    ans[0] = x[0];
    for (int i = 0; i < n - 1; i++) {
        double d = x[r[i]+1] - x[r[i]];
        ans[i+1] = ans[i] + d;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}