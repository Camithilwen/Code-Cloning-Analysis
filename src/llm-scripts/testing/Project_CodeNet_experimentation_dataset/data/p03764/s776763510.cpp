#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}




const int MOD = 1E9 + 7;
void _main() {
        int n, m; cin >> n >> m;
        vector<int> x(n), y(m); cin >> x >> y;

        auto solve = [](vector<int> a) {
                ll ans = 0, pre = 0;
                int n = sz(a);
                for (int i = 0; i < n; i++) {
                        ans += (ll) i * a[i] - (ll)(n - i - 1) * a[i];
                        ans += MOD;
                        ans %= MOD;
                }

                return ans;
        };

        cout << solve(x) * solve(y) % MOD;
}




signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
