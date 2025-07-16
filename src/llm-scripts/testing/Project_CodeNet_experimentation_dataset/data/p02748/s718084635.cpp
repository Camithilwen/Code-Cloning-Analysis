#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    int A, B, m; cin >> A >> B >> m;
    V<int> a(A), b(B);
    int amin = 1e9, bmin = 1e9;
    for(int i = 0; i < A; i++){
        cin >> a[i];
        amin = min(a[i], amin);
    }
    for(int i = 0; i < B; i++){
        cin >> b[i];
        bmin = min(b[i], bmin);
    }

    V<int> x(m), y(m), c(m);
    for(int i = 0; i < m; i++){
        int xx, yy, cc; cin >> xx >> yy >> cc;
        xx--, yy--;
        x[i] = xx;
        y[i] = yy;
        c[i] = cc;
    }

    int ans = 1e9;
    for(int i = 0; i < m; i++){
        ans = min(a[x[i]] + b[y[i]] - c[i], ans);
    }

    cout << min(ans, amin + bmin) << endl;

    return 0;
}
