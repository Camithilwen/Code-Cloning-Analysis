#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}




void _main() {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> w(n), e(n);
        for (int i = 0; i < n; i++) {
                if (i) w[i] = w[i - 1];
                w[i] += s[i] == 'W';
        }

        for (int i = n - 1; i >= 0; i--) {
                if (i + 1 < n) e[i] = e[i + 1];
                e[i] += s[i] == 'E';
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
                ans = min(ans, (i ? w[i - 1] : 0) + (i + 1 < n ? e[i + 1] : 0));
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
