#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);

    // cout << 1.0 / 2 << endl;
    
    int n, m, d; cin >> n >> m >> d;

    // 隣り合う二項はm-1個ある
    // (a, b)並んでいた場合の期待値を求めて、それをm-1倍する

    double ans = 0.0;

    double e = 0.0;

    if (d == 0) {
        e = double(1.0) / n;
    } else {
        e = double(2.0);
        ll n2 = ll(n) * n;
        e *= (n-d);
        e /= n2;
    }
    cout << e * (m-1) << endl;
    return 0;
}